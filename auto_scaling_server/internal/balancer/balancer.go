package balancer

import (
	"fmt"
	"net/http"
	"net/http/httputil"
	"net/url"
	"sync"

	"autoscaling-server/internal/autoscaler"
)

var (
	next int
	mu   sync.Mutex
)

func GetNextServer() string {
	mu.Lock()
	defer mu.Unlock()

	activeServers := autoscaler.GetActiveServers()
	if len(activeServers) == 0 {
		return ""
	}

	server := activeServers[next%len(activeServers)]
	next++
	return server
}

func HandleRequest(w http.ResponseWriter, r *http.Request) {
	target := GetNextServer()
	if target == "" {
		http.Error(w, "No active servers available", http.StatusServiceUnavailable)
		return
	}

	fmt.Println("Forwarding request to:", target)

	u, _ := url.Parse(target)

	proxy := httputil.NewSingleHostReverseProxy(u)

	r.URL.Host = u.Host
	r.URL.Scheme = u.Scheme
	r.Host = u.Host

	proxy.ServeHTTP(w, r)
}
