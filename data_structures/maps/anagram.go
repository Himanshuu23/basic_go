package main

import (
	"fmt"
	"strings"
	"sort"
	"regexp"
)

func main() {
	words := []string{ "bat", "tab", "cat", "act" }

	anagram(words)
}

func anagram(words []string) {
	Map := make(map[string][]string)

	for _, word := range words {
		values := strings.Split(word, "")
		sort.Strings(values)
		key := strings.Join(values, "")

		regex := fmt.Sprintf(".*[%s].*?", key)
		matched, _ := regexp.MatchString(regex, word)

		if matched {
			Map[key] = append(Map[key], word)
		}
	}

	fmt.Println(Map)
}
