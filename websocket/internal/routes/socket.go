package routes

import (
	"net/http"
	"socket/internal/handlers"
)

func RegisterRoutes() {
	http.HandleFunc("/ws", handlers.HandleWebsocket)
}
