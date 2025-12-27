package main

import (
    "log"
    "net/http"
    "server/internal/config"
    "server/internal/redis"
    "server/internal/sharding"
    "server/internal/signaling"

    "github.com/prometheus/client_golang/prometheus/promhttp"
)

func main() {
    cfg := config.Load()

    redisClient, err := redis.NewClient(cfg.RedisURL)
    if err != nil {
        log.Fatal("Failed to connect to Redis:", err)
    }
    defer redisClient.Close()

    sharder := sharding.NewSharder(cfg.ServerID, 3)

    handler := signaling.NewHandler(cfg, redisClient, sharder)

    http.HandleFunc("/ws", handler.HandleWebSocket)
    http.HandleFunc("/health", handler.HandleHealth)
    http.Handle("/metrics", promhttp.Handler())

    log.Printf("Server %s starting on port %s", cfg.ServerID, cfg.Port)
    log.Printf("Metrics available at /metrics")
    
    if err := http.ListenAndServe(":"+cfg.Port, nil); err != nil {
        log.Fatal("ListenAndServe error:", err)
    }
}
