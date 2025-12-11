package handlers

import (
	"fmt"
	"net/http"
	"socket/internal/config"

	"github.com/gorilla/websocket"
)

var upgrader = websocket.Upgrader{
	ReadBufferSize: config.ReadBufferSize,
	WriteBufferSize: config.WriteBufferSize,
	CheckOrigin: func(r *http.Request) bool{
		return true	
	},
}

func HandleWebsocket(w http.ResponseWriter, r *http.Request) {
	conn, err := upgrader.Upgrade(w, r, nil)
	if err != nil {
		fmt.Println(err)
		return
	}

	defer conn.Close()

	for {
		messageType, data, err := conn.ReadMessage()
		if err != nil {
			fmt.Println(err)
			return
		}

		fmt.Printf("Received Message: %s\n", data)

		if err := conn.WriteMessage(messageType, data); err != nil {
			fmt.Println(err)
			return
		}
	}
}

