package main

import "fmt"

type Trie struct {
	isEnd		bool
	children	map[rune]*Trie
}

func NewTrie() *Trie {
	return &Trie{ children: make(map[rune]*Trie) }
}

func (t *Trie) Insert (word string) {
	node := t
	for _, char := range word {
		if _, found := node.children[char]; !found {
			node.children[char] = NewTrie()
		}

		node = node.children[char]
	}

	node.isEnd = true
}

func (t *Trie) Search (word string) bool {
	node := t
	for _, char := range word {
		if next, found := node.children[char]; found {
			node = next
		} else {
			return false
		}
	}

	return node.isEnd
}

func (t *Trie) StartsWith (prefix string) bool {
	node := t
	for _, char := range prefix {
		if next, found := node.children[char]; found {
			node = next
		} else {
			return false
		}
	}

	return true
}

func main() {
	trie := NewTrie()
	trie.Insert("mango")
	fmt.Println(trie.Search("mango"))
	fmt.Println(trie.Search("man"))
	fmt.Println(trie.StartsWith("man"))
}
