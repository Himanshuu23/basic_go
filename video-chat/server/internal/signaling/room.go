package signaling

import (
    "sync"

    "github.com/gorilla/websocket"
)

type Client struct {
    ID       string
    Conn     *websocket.Conn
    Room     string
    ServerID string
}

type Room struct {
    ID      string
    Clients map[string]*Client
    mu      sync.RWMutex
}

func NewRoom(id string) *Room {
    return &Room{
        ID:      id,
        Clients: make(map[string]*Client),
    }
}

func (r *Room) AddClient(client *Client) {
    r.mu.Lock()
    defer r.mu.Unlock()
    r.Clients[client.ID] = client
}

func (r *Room) RemoveClient(clientID string) {
    r.mu.Lock()
    defer r.mu.Unlock()
    delete(r.Clients, clientID)
}

func (r *Room) GetClient(clientID string) (*Client, bool) {
    r.mu.RLock()
    defer r.mu.RUnlock()
    client, exists := r.Clients[clientID]
    return client, exists
}

func (r *Room) GetAllClients() []*Client {
    r.mu.RLock()
    defer r.mu.RUnlock()
    clients := make([]*Client, 0, len(r.Clients))
    for _, client := range r.Clients {
        clients = append(clients, client)
    }
    return clients
}

func (r *Room) GetClientCount() int {
    r.mu.RLock()
    defer r.mu.RUnlock()
    return len(r.Clients)
}
