package main

import (
	"encoding/json"
	"log"
	"net/http"
	"sync"

	"github.com/gorilla/websocket"
)

var upgrader = websocket.Upgrader{
	CheckOrigin: func(r *http.Request) bool {
		return true
	},
}

type Client struct {
	ID   string
	Conn *websocket.Conn
	Room string
}

type Message struct {
	Type    string          `json:"type"`
	From    string          `json:"from"`
	To      string          `json:"to"`
	Room    string          `json:"room"`
	Payload json.RawMessage `json:"payload"`
}

type Room struct {
	Clients map[string]*Client
	mu      sync.RWMutex
}

var (
	rooms = make(map[string]*Room)
	mu    sync.RWMutex
)

func getOrCreateRoom(roomID string) *Room {
	mu.Lock()
	defer mu.Unlock()

	if room, exists := rooms[roomID]; exists {
		return room
	}

	room := &Room{
		Clients: make(map[string]*Client),
	}
	rooms[roomID] = room
	return room
}

func handleWebSocket(w http.ResponseWriter, r *http.Request) {
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		log.Println("Upgrade error:", err)
		return
	}

	client := &Client{
		Conn: conn,
	}

	defer func() {
		if client.Room != "" {
			room := getOrCreateRoom(client.Room)
			room.mu.Lock()
			delete(room.Clients, client.ID)
			room.mu.Unlock()

			room.mu.RLock()
			for _, c := range room.Clients {
				leaveMsg := Message{
					Type: "user-left",
					From: client.ID,
				}
				c.Conn.WriteJSON(leaveMsg)
			}
			room.mu.RUnlock()
		}
		conn.Close()
	}()

	for {
		var msg Message
		err := conn.ReadJSON(&msg)
		if err != nil {
			log.Println("Read error:", err)
			break
		}

		switch msg.Type {
		case "join":
			client.ID = msg.From
			client.Room = msg.Room
			room := getOrCreateRoom(msg.Room)

			room.mu.Lock()
			room.Clients[client.ID] = client
			room.mu.Unlock()

			room.mu.RLock()
			userList := []string{}
			for id := range room.Clients {
				if id != client.ID {
					userList = append(userList, id)
				}
			}
			room.mu.RUnlock()

			conn.WriteJSON(map[string]interface{}{
				"type":  "users",
				"users": userList,
			})

			room.mu.RLock()
			for id, c := range room.Clients {
				if id != client.ID {
					joinMsg := Message{
						Type: "user-joined",
						From: client.ID,
					}
					c.Conn.WriteJSON(joinMsg)
				}
			}
			room.mu.RUnlock()

		case "offer", "answer", "ice-candidate":
			room := getOrCreateRoom(client.Room)
			room.mu.RLock()
			if targetClient, exists := room.Clients[msg.To]; exists {
				msg.From = client.ID
				targetClient.Conn.WriteJSON(msg)
			}
			room.mu.RUnlock()
		}
	}
}

func main() {
	http.HandleFunc("/ws", handleWebSocket)

	log.Println("WebSocket server starting on :8080")
	err := http.ListenAndServe(":8080", nil)
	if err != nil {
		log.Fatal("ListenAndServe error:", err)
	}
}
