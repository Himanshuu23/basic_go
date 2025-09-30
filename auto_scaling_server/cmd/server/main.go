package main

import (
    "time"

    "autoscaling-server/internal/metrics"
    "github.com/gin-gonic/gin"
)

func main() {
    router := gin.Default()
    
    router.GET("/health", func(c *gin.Context) {
        start := time.Now()
        c.JSON(200, gin.H{"status": "ok"})

        latency := float64(time.Since(start).Milliseconds())
        metrics.RecordRecord(latency)
    })

    router.GET("/metrics", func(c *gin.Context) {
        c.JSON(200, metrics.ServerMetrics)
    })

    router.Run("localhost:11011")
}
