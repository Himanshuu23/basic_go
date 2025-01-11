package main

import "fmt"

func main() {
	Array := []int{1, 2, 3, 4, 5}
	array1 := add(3, 2, Array)
	array2 := remove(2, Array)
	fmt.Println(array1, array2)
}

func add(element int, index int, array []int) []int {
	array = append(array[:index], append([]int{element}, array[index:]...)...)
	return array
}

func remove(index int, array []int) []int {
	array = append(array[:index], array[index+1:]...)
	return array
}
