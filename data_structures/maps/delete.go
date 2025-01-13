package main

import "fmt"

func main() {
	Map := make(map[string]int)

	Map["a"] = 100
	Map["b"] = 200
	Map["c"] = 300

	fmt.Println(Map)

	delete(Map, "a")

	fmt.Println(Map)
}
