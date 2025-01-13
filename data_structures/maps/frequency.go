package main

import "fmt"

func main() {
	var word string

	fmt.Println("Enter the word: ")
	fmt.Scanln(&word)

	frequency(word)
}

func frequency(word string) {
	count := make(map[string]int)

	for _, char := range word {
		if _, found := count[string(char)]; found {
			count[string(char)]++
		} else {
			count[string(char)] = 1
		}
	}

	fmt.Println(count)
}
