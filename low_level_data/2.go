package main

import (
	"fmt"
)

func main() {
	word := "something"
	bytes := []byte(word)
	back := string(bytes[:])

	fmt.Println(bytes, back)
}
