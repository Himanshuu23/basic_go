package metrics

import (
    "github.com/prometheus/client_golang/prometheus"
    "github.com/prometheus/client_golang/prometheus/promauto"
)

var (
    ActiveConnections = promauto.NewGauge(prometheus.GaugeOpts{
        Name: "videochat_active_connections",
        Help: "Number of active WebSocket connections",
    })

    TotalRooms = promauto.NewGauge(prometheus.GaugeOpts{
        Name: "videochat_total_rooms",
        Help: "Total number of active rooms",
    })

    MessagesProcessed = promauto.NewCounterVec(prometheus.CounterOpts{
        Name: "videochat_messages_processed_total",
        Help: "Total number of messages processed by type",
    }, []string{"type"})

    ConnectionDuration = promauto.NewHistogram(prometheus.HistogramOpts{
        Name:    "videochat_connection_duration_seconds",
        Help:    "Duration of WebSocket connections",
        Buckets: prometheus.DefBuckets,
    })
)
