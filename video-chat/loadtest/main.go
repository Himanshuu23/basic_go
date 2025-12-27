package main

import (
    "fmt"
    "log"
    "os"
    "strconv"
    "sync"
    "time"

    "github.com/gorilla/websocket"
)

type Client struct {
    ID   string
    Conn *websocket.Conn
    Room string
}

func main() {
    wsURL := os.Getenv("WS_URL")
    if wsURL == "" {
        wsURL = "ws://localhost/ws"
    }

    numUsersStr := os.Getenv("NUM_USERS")
    numUsers, err := strconv.Atoi(numUsersStr)
    if err != nil || numUsers == 0 {
        numUsers = 100
    }

    roomID := os.Getenv("ROOM_ID")
    if roomID == "" {
        roomID = "loadtest-room"
    }

    log.Printf("Starting load test: %d users connecting to %s in room %s", numUsers, wsURL, roomID)

    var wg sync.WaitGroup
    successCount := 0
    failCount := 0
    mu := sync.Mutex{}

    startTime := time.Now()

    for i := 0; i < numUsers; i++ {
        wg.Add(1)
        go func(index int) {
            defer wg.Done()

            client := &Client{
                ID:   fmt.Sprintf("loadtest-user-%d", index),
                Room: roomID,
            }

            if err := connectClient(client, wsURL); err != nil {
                mu.Lock()
                failCount++
                mu.Unlock()
                log.Printf("Client %d failed: %v", index, err)
                return
            }

            mu.Lock()
            successCount++
            mu.Unlock()

            time.Sleep(60 * time.Second)
            client.Conn.Close()
        }(i)

        if i%100 == 0 && i > 0 {
            time.Sleep(1 * time.Second)
            log.Printf("Connected %d users...", i)
        }
    }

    wg.Wait()
    duration := time.Since(startTime)

    log.Printf("\n=== Load Test Results ===")
    log.Printf("Total Users: %d", numUsers)
    log.Printf("Successful: %d", successCount)
    log.Printf("Failed: %d", failCount)
    log.Printf("Duration: %v", duration)
    log.Printf("Connections/sec: %.2f", float64(successCount)/duration.Seconds())
}

func connectClient(client *Client, wsURL string) error {
    dialer := websocket.Dialer{
        HandshakeTimeout: 10 * time.Second,
    }

    conn, _, err := dialer.Dial(wsURL, nil)
    if err != nil {
        return fmt.Errorf("dial error: %w", err)
    }

    client.Conn = conn

    joinMsg := map[string]interface{}{
        "type": "join",
        "from": client.ID,
        "room": client.Room,
    }

    if err := conn.WriteJSON(joinMsg); err != nil {
        return fmt.Errorf("write error: %w", err)
    }

    go func() {
        for {
            var msg map[string]interface{}
            if err := conn.ReadJSON(&msg); err != nil {
                return
            }
        }
    }()

    return nil
}
