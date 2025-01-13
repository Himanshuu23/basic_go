package main

import "fmt"

func main() {
	Map := map[string]int{ "a": 1, "b": 2, "c": 3, "d": 4 }

	reverse(Map)
}

func reverse(Map map[string]int) {
	reversed := make(map[string]int)
	keys := []string{}

	for key := range Map {
		keys = append(keys, key)
	}

	for i := len(keys) - 1; i >= 0; i-- {
			reversed[keys[i]] = Map[keys[i]] 
	}

	fmt.Println(reversed)
}
