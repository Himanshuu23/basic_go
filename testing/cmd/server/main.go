package main

import (
	"fmt"
	"net/http"

	"tests/internals/config"
	"tests/internals/routes"
)

func main() {
	routes.HandleRoute()
	fmt.Printf("Server running on : %s", config.Port)

	if err := http.ListenAndServe(config.Port, nil); err != nil {
		fmt.Printf("Error occured : %v", err.Error())
	}
}
