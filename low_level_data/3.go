package main

import "fmt"

func main() {
	word := "something"

	bytes := []byte(word)

	for i := range word {
		fmt.Println(string(word[i]), "->", bytes[i])
	}
}
