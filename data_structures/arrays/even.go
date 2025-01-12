package main

import "fmt"

func main() {
	array := []int{1, 2, 3, 4, 5, 6}
	New := even(array)
	fmt.Println(New)
}

func remove(array []int, index int) []int {
	Array := append(array[:index], array[index+1:]...)
	return Array
}

func even(array []int) []int {
	for i := range array {
		if array[i] % 2 == 0 {
			array = remove(array, i)
		}
	} 

	return array
}
