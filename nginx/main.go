package main

import (
	"fmt"
	"os"
	"net/http"
)

func main() {
	name := os.Getenv("SERVER_NAME")
	if name == "" {
		name = "unknown"
	}

	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		fmt.Fprintf(w, "Hello from %s\n", name)
	})

	http.ListenAndServe(":80", nil)
}
