package redis

import (
    "context"
    "encoding/json"
    "fmt"
    "log"
    "time"

    "github.com/redis/go-redis/v9"
)

type Client struct {
    rdb *redis.Client
    ctx context.Context
}

type Message struct {
    Type      string          `json:"type"`
    From      string          `json:"from"`
    To        string          `json:"to"`
    Room      string          `json:"room"`
    ServerID  string          `json:"server_id"`
    Payload   json.RawMessage `json:"payload"`
    Timestamp int64           `json:"timestamp"`
}

func NewClient(addr string) (*Client, error) {
    rdb := redis.NewClient(&redis.Options{
        Addr: addr,
    })

    ctx := context.Background()
    if err := rdb.Ping(ctx).Err(); err != nil {
        return nil, fmt.Errorf("failed to connect to Redis: %w", err)
    }

    log.Println("Connected to Redis")
    return &Client{rdb: rdb, ctx: ctx}, nil
}

func (c *Client) PublishMessage(msg *Message) error {
    msg.Timestamp = time.Now().Unix()
    data, err := json.Marshal(msg)
    if err != nil {
        return err
    }

    channel := fmt.Sprintf("room:%s", msg.Room)
    return c.rdb.Publish(c.ctx, channel, data).Err()
}

func (c *Client) Subscribe(room string, handler func(*Message)) error {
    channel := fmt.Sprintf("room:%s", room)
    pubsub := c.rdb.Subscribe(c.ctx, channel)
    defer pubsub.Close()

    ch := pubsub.Channel()
    for msg := range ch {
        var message Message
        if err := json.Unmarshal([]byte(msg.Payload), &message); err != nil {
            log.Printf("Error unmarshaling message: %v", err)
            continue
        }
        handler(&message)
    }

    return nil
}

func (c *Client) AddUserToRoom(room, userID, serverID string) error {
    key := fmt.Sprintf("room:%s:users", room)
    data := map[string]string{
        "user_id":   userID,
        "server_id": serverID,
        "joined_at": fmt.Sprintf("%d", time.Now().Unix()),
    }
    jsonData, _ := json.Marshal(data)
    return c.rdb.HSet(c.ctx, key, userID, jsonData).Err()
}

func (c *Client) RemoveUserFromRoom(room, userID string) error {
    key := fmt.Sprintf("room:%s:users", room)
    return c.rdb.HDel(c.ctx, key, userID).Err()
}

func (c *Client) GetRoomUsers(room string) ([]string, error) {
    key := fmt.Sprintf("room:%s:users", room)
    result, err := c.rdb.HKeys(c.ctx, key).Result()
    if err != nil {
        return nil, err
    }
    return result, nil
}

func (c *Client) SetRoomShard(room, serverID string) error {
    key := fmt.Sprintf("room:%s:shard", room)
    return c.rdb.Set(c.ctx, key, serverID, 24*time.Hour).Err()
}

func (c *Client) GetRoomShard(room string) (string, error) {
    key := fmt.Sprintf("room:%s:shard", room)
    return c.rdb.Get(c.ctx, key).Result()
}

func (c *Client) Close() error {
    return c.rdb.Close()
}
