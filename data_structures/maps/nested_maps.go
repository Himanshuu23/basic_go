package main

import "fmt"

func main() {
	Map := map[string]map[string]int{
		"A": { "GDP": 355, "population": 1000 },
		"B": { "GDP": 705, "population": 5000 },
	}

	for key, value := range Map {
		fmt.Println(key, value)
		for i, j := range value {
			fmt.Println(i, j)
		}
	}
}
