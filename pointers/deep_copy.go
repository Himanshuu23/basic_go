package main

import "fmt"

func main() {
	Array := []int{1, 2, 3, 4, 5}
	clone := Copy(Array)
	fmt.Println(clone)
}

func Copy(Array []int) []int {
	array := []int{}

	for i := range Array {
		ptr := &Array[i]
		array = append(array, *ptr)
	}

	return array
}
