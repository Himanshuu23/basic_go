package main

import "fmt"

func main() {
	map1 := map[string]int{ "a": 1, "b": 2, "c": 3 }
	map2 := map[string]int{ "a": 2, "e": 4, "f": 5 }

	merge(map1, map2)
}

func merge(map1 ,map2 map[string]int) {
	Map := map1

	for key := range map2 {
		if _, found := Map[key]; found {
			continue
		} else {
			Map[key] = map2[key]
		}
	}

	fmt.Println(Map)
}
