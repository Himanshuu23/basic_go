package main

import (
	"fmt"
	"net/http"
	"os"
)

func handler(w http.ResponseWriter, r *http.Request) {
	host, _ := os.Hostname()
	fmt.Fprintln(w, "Response from ", host)
}

func main() {
	http.HandleFunc("/", handler)

	http.ListenAndServe(":90", nil)
}
