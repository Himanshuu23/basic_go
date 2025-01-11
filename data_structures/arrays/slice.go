package main

import "fmt"

func main() {
	Array := []int{1, 2, 3, 4, 5}
	array := add(3, 2, Array)
	fmt.Println(array)
}

func add(element int, index int, array []int) []int {
	array = append(array[:index], append([]int{element}, array[index:]...)...)
	return array
}
