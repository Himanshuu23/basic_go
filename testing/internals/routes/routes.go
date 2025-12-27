package routes

import (
	"net/http"

	"tests/internals/handlers"
)

func HandleRoute() {
	http.HandleFunc("/", handlers.Handler)
}
