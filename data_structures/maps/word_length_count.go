package main

import (
	"fmt"
	"strings"
)

func main() {
	words := "This is some random string for testing the function"
	wordCount(words)
}

func wordCount(words string) {
	array := strings.Split(words," ")
	Map := make(map[int][]string)

	for _, word := range array {
		Map[len(word)] = append(Map[len(word)], word)
	}

	fmt.Println(Map)
}
