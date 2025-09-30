package balancer

import (
    "net/http"
    "net/http/httputil"
    "net/url"
    "sync"
)

var (
    servers     []string
    next        int
    mu          sync.Mutex
)

func Init(serverList []string) {
    servers = serverList
}

func getNextServer() string {
    mu.Lock()
    defer mu.Unlock()
    server := servers[next%len(servers)]
    next++
    return server
}

func HandleRequest(w http.ResponseWriter, r *http.Request) {
    target := getNextServer()
    url, _ := url.Parse(target)

    proxy := httputil.NewSingleHostReverseProxy(url)
    proxy.ServeHTTP(w, r)
}
