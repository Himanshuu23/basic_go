package autoscaler

import (
	"autoscaling-server/internal/metrics"
	"fmt"
	"os"
	"os/exec"
	"time"
)

const (
    CPU_SCALE_UP        = 30.0
    CPU_SCALE_DOWN      = 10.0
    MIN_SERVERS         = 1
    MAX_SERVERS         = 5
)

var serverMap = make(map[int]*exec.Cmd)

func StartServer(port int) {
    cmd := exec.Command("go", "run", "cmd/server/main.go")
    cmd.Env = append(os.Environ(), fmt.Sprintf("PORT=%d", port))
    cmd.Start()
    serverMap[port] = cmd
}

func StopServer(port int) {
    if cmd, ok := serverMap[port]; ok {
        cmd.Process.Kill()
        delete(serverMap, port)
    }
}

func nextAvailablePort() int {
    basePort := 11011

    for i := 0; i < MAX_SERVERS; i++ {
        port := basePort + i
        if _, exists := serverMap[port]; !exists {
            return port
        }
    }

    return 0
}

func serverToRemove() int {
    for port := range serverMap {
        return port
    }

    return 0
}

func MonitorAndScale() {
    go func() {
        for {
            metrics := metrics.ServerMetrics

            if metrics.CPUUsage > CPU_SCALE_UP {
                StartServer(nextAvailablePort())
            } else if metrics.CPUUsage < CPU_SCALE_DOWN && len(serverMap) > MIN_SERVERS {
                StopServer(serverToRemove())
            }

            time.Sleep(5 * time.Second)
        }
    }()
}
