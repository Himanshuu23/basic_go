package main

import "fmt"

func main() {
	words := [10]byte{45, 46, 47, 48, 49, 50, 31, 32, 43, 33}
	fmt.Println(words)

	words[4] = 255
	fmt.Println(words)
}
