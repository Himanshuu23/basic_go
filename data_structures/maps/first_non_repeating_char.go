package main

import "fmt"

func main() {
	word := "someone"

	nonRepeatingChar(word)
}

func nonRepeatingChar(word string) {
	Map := make(map[string]int)

	for _, char := range word {
		if _, found := Map[string(char)]; found {
			fmt.Println(string(char))
			break
		} else {
			Map[string(char)] = 1
		}
	}
}
