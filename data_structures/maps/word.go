package main

import (
	"fmt"
	"strings"
)

func main() {
	words := "This is a string to test the function for the problem."
	frequency(words)
}

func frequency(words string) {
	word := strings.Split(words, " ")
	count := make(map[string]int)

	for _, i := range word {
		if _, found := count[string(i)]; found {
			count[string(i)] += 1
		} else {
			count[string(i)] = 1
		}
	}

	fmt.Println(count)
}
