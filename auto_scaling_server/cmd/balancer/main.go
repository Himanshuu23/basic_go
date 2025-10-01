package main

import (
    "net/http"
    "autoscaling-server/internal/balancer"
)

func main() {
    http.HandleFunc("/", balancer.HandleRequest)
    http.ListenAndServe(":8080", nil)
}
