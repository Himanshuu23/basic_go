package main

import "fmt"

func main() {
	words := []string{ "something", "similar", "for", "apple", "animals" , "are", "amazing" }

	prefix(words)
}

func prefix(words []string) {
	prefixes := make(map[string][]string)

	for _, word := range words {
		firstChar := string(word[0])
		prefixes[firstChar] = append(prefixes[firstChar], word)
	}

	fmt.Println(prefixes)
}
