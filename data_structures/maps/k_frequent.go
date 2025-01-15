package main

import (
	"fmt"
)

func main() {
	words := []string{
		"i", "am", "something", "i", "am", "go", "go", "is", "great",
		"i", "am", "go", "go", "i", "like", "go", "something", "go", "go",
		"i", "something", "go", "am", "is",
	}


	kfrequent(words, 3)
}

func kfrequent(words []string, k int) {
	Map := make(map[string]int)
	result := []string{}

	for _, char := range words {
		if _, found := Map[char]; found {
			Map[char] += 1
		} else {
			Map[char] = 1
		}
	}

	for len(result) < k {
		word := ""
		Map, word = biggest(Map)
		result = append(result, word)
	}

	fmt.Print(result)
}

func biggest(Map map[string]int) (map[string]int, string) {
	word, value := "", -1 << 63
	
	for key, val := range Map {
		if val > value {
			word = key
		}
	}

	delete(Map, word)
	return Map, word
}
