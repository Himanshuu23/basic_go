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
	fmt.Println("the order of the maps does not depends on insertion and it is completely random - so we can just change the printing order and achieve the same")
}
