package main

import (
	"fmt"
	"slices"
)

func main() {
	Map := map[string][]string{ "Electrical Engineering": {"A", "B", "C", "D"}, "Computer Science Engineering": {"X", "Y", "Z"} }

	add("someone", "Computer Science Engineering", Map)
	Delete("C", "Electrical Engineering", Map)
}

func add(employee string, key string, Map map[string][]string) {
	Map[key] = append(Map[key], employee)
	fmt.Println(Map)
}

func Delete(employee string, key string, Map map[string][]string) {
	index := slices.Index(Map[key], employee)

	Map[key] = append(Map[key][:index], Map[key][index+1:]...)

	fmt.Println(Map)
}
