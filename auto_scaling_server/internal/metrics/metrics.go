package metrics

import (
    "time"

    "github.com/shirou/gopsutil/cpu"
    "github.com/shirou/gopsutil/mem"
)

type Metrics struct {
    CPUUsage        float64
    MemoryUsage     uint64
    RequestCount    int
    AvgLatencyMS    float64
}

var ServerMetrics Metrics

func StartMetricsCollector() {
    go func () {
        for {
            cpuPercent, _ := cpu.Percent(time.Second, false)
            vMem, _ := mem.VirtualMemory()

            ServerMetrics.CPUUsage = cpuPercent[0]
            ServerMetrics.MemoryUsage = vMem.Used

            time.Sleep(5 * time.Second)
        }
    }()
}

func RecordRecord(latency float64) {
    ServerMetrics.RequestCount++

    ServerMetrics.AvgLatencyMS = (ServerMetrics.AvgLatencyMS + latency) / 2
}
