package main

import (
	"encoding/base64"
	"fmt"
)

func main() {
	data := []byte("Hello World")

	encoded := base64.StdEncoding.EncodeToString(data)
	fmt.Println(encoded)

	decoded := base64.StdEncoding.DeocdeToString(encoded)
	fmt.Println(decoded)
}
