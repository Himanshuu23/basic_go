package main

import (
	"fmt"
	"net/http"
	"socket/internal/routes"
	"socket/internal/config"
)

func main() {
	routes.RegisterRoutes()

	fmt.Println("Websocket server is running on :8080/ws")
	if err := http.ListenAndServe(config.ServerPort, nil); err != nil {
		fmt.Println(err)
	}
}
