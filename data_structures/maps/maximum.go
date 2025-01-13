package main

import "fmt"

func main() {
	students := make(map[string]int)
	
	students["a"] = 100
	students["b"] = 200
	students["c"] = 300
	students["d"] = 400

	maximum(students)
}

func maximum(Map map[string]int) {
	var maximum string
	val := -1 << 63

	for key := range Map {
		if Map[key] > val {
			maximum = key
		} else {
			continue
		}
	}

	fmt.Println(maximum)
}
