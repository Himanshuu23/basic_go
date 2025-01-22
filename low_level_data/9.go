package main

import (
	"fmt"
	"bytes"
)

func main() {
	var buf bytes.Buffer

	buf.Write([]byte("hello world"))
	
	data := buf.String()

	fmt.Print(data)
}
