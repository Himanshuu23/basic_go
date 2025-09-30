package main

import (
    "net/http"
    
    "autoscaling-server/internal/balancer"
)

func main() {
    balancer.Init([]string{
        "http://localhost:11011",
    })

    http.HandleFunc("/", balancer.HandleRequest)

    http.ListenAndServe(":8080", nil)
}
