package signaling

import (
    "encoding/json"
    "log"
    "net/http"
    "sync"
    "server/internal/config"
    "server/internal/redis"
    "server/internal/sharding"

    "github.com/gorilla/websocket"
    "github.com/google/uuid"
)

var upgrader = websocket.Upgrader{
    CheckOrigin: func(r *http.Request) bool {
        return true
    },
}

type Handler struct {
    config      *config.Config
    redisClient *redis.Client
    sharder     *sharding.Sharder
    rooms       map[string]*Room
    roomsMu     sync.RWMutex
    subscribers map[string]chan struct{}
    subMu       sync.Mutex
}

func NewHandler(cfg *config.Config, redisClient *redis.Client, sharder *sharding.Sharder) *Handler {
    return &Handler{
        config:      cfg,
        redisClient: redisClient,
        sharder:     sharder,
        rooms:       make(map[string]*Room),
        subscribers: make(map[string]chan struct{}),
    }
}

func (h *Handler) HandleWebSocket(w http.ResponseWriter, r *http.Request) {
    conn, err := upgrader.Upgrade(w, r, nil)
    if err != nil {
        log.Println("Upgrade error:", err)
        return
    }

    client := &Client{
        ID:       uuid.New().String(),
        Conn:     conn,
        ServerID: h.config.ServerID,
    }

    defer func() {
        if client.Room != "" {
            h.handleClientLeave(client)
        }
        conn.Close()
    }()

    for {
        var msg map[string]interface{}
        err := conn.ReadJSON(&msg)
        if err != nil {
            log.Println("Read error:", err)
            break
        }

        msgType, _ := msg["type"].(string)

        switch msgType {
        case "join":
            h.handleJoin(client, msg)
        case "offer", "answer", "ice-candidate":
            h.handleSignaling(client, msg)
        }
    }
}

func (h *Handler) handleJoin(client *Client, msg map[string]interface{}) {
    roomID, _ := msg["room"].(string)
    userID, _ := msg["from"].(string)

    client.ID = userID
    client.Room = roomID

    room := h.getOrCreateRoom(roomID)
    room.AddClient(client)

    h.redisClient.AddUserToRoom(roomID, userID, h.config.ServerID)
    h.redisClient.SetRoomShard(roomID, h.config.ServerID)

    h.startRoomSubscription(roomID)

    users, _ := h.redisClient.GetRoomUsers(roomID)
    localUsers := []string{}
    for _, uid := range users {
        if uid != userID {
            localUsers = append(localUsers, uid)
        }
    }

    client.Conn.WriteJSON(map[string]interface{}{
        "type":  "users",
        "users": localUsers,
    })

    h.redisClient.PublishMessage(&redis.Message{
        Type:     "user-joined",
        From:     userID,
        Room:     roomID,
        ServerID: h.config.ServerID,
    })

    log.Printf("User %s joined room %s on server %s (total users: %d)", userID, roomID, h.config.ServerID, len(localUsers)+1)
}

func (h *Handler) handleSignaling(client *Client, msg map[string]interface{}) {
    msgType, _ := msg["type"].(string)
    to, _ := msg["to"].(string)
    payload, _ := json.Marshal(msg["payload"])

    redisMsg := &redis.Message{
        Type:     msgType,
        From:     client.ID,
        To:       to,
        Room:     client.Room,
        ServerID: h.config.ServerID,
        Payload:  payload,
    }

    h.redisClient.PublishMessage(redisMsg)
}

func (h *Handler) handleClientLeave(client *Client) {
    room := h.getOrCreateRoom(client.Room)
    room.RemoveClient(client.ID)

    h.redisClient.RemoveUserFromRoom(client.Room, client.ID)

    h.redisClient.PublishMessage(&redis.Message{
        Type:     "user-left",
        From:     client.ID,
        Room:     client.Room,
        ServerID: h.config.ServerID,
    })

    log.Printf("User %s left room %s", client.ID, client.Room)
}

func (h *Handler) startRoomSubscription(roomID string) {
    h.subMu.Lock()
    if _, exists := h.subscribers[roomID]; exists {
        h.subMu.Unlock()
        return
    }
    stop := make(chan struct{})
    h.subscribers[roomID] = stop
    h.subMu.Unlock()

    go func() {
        defer func() {
            h.subMu.Lock()
            delete(h.subscribers, roomID)
            h.subMu.Unlock()
        }()

        msgChan := make(chan *redis.Message, 100)
        
        go func() {
            h.redisClient.Subscribe(roomID, func(msg *redis.Message) {
                select {
                case msgChan <- msg:
                case <-stop:
                    return
                }
            })
        }()

        for {
            select {
            case msg := <-msgChan:
                h.handleRedisMessage(msg)
            case <-stop:
                return
            }
        }
    }()
}

func (h *Handler) handleRedisMessage(msg *redis.Message) {
    room := h.getOrCreateRoom(msg.Room)

    switch msg.Type {
    case "user-joined":
        clients := room.GetAllClients()
        for _, client := range clients {
            if client.ID != msg.From {
                client.Conn.WriteJSON(map[string]interface{}{
                    "type": "user-joined",
                    "from": msg.From,
                })
            }
        }

    case "offer", "answer", "ice-candidate":
        if client, exists := room.GetClient(msg.To); exists {
            var payload interface{}
            json.Unmarshal(msg.Payload, &payload)
            client.Conn.WriteJSON(map[string]interface{}{
                "type":    msg.Type,
                "from":    msg.From,
                "payload": payload,
            })
        }

    case "user-left":
        clients := room.GetAllClients()
        for _, client := range clients {
            client.Conn.WriteJSON(map[string]interface{}{
                "type": "user-left",
                "from": msg.From,
            })
        }
    }
}

func (h *Handler) getOrCreateRoom(roomID string) *Room {
    h.roomsMu.Lock()
    defer h.roomsMu.Unlock()

    if room, exists := h.rooms[roomID]; exists {
        return room
    }

    room := NewRoom(roomID)
    h.rooms[roomID] = room
    return room
}

func (h *Handler) HandleHealth(w http.ResponseWriter, r *http.Request) {
    w.WriteHeader(http.StatusOK)
    json.NewEncoder(w).Encode(map[string]string{
        "status":    "healthy",
        "server_id": h.config.ServerID,
    })
}
