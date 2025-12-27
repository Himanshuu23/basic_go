package config

import (
    "os"
)

type Config struct {
    ServerID  string
    RedisURL  string
    Port      string
    SFUPort   string
}

func Load() *Config {
    return &Config{
        ServerID:  getEnv("SERVER_ID", "signaling-1"),
        RedisURL:  getEnv("REDIS_URL", "localhost:6379"),
        Port:      getEnv("PORT", "8080"),
        SFUPort:   getEnv("SFU_PORT", "7000"),
    }
}

func getEnv(key, defaultValue string) string {
    if value := os.Getenv(key); value != "" {
        return value
    }
    return defaultValue
}
