package main

import "fmt"

func main() {
	array := []int{1, 2, 3, 4, 5, 6}
	New := even(array)
	fmt.Println(New)
}

func even(array []int) []int {
	Array := []int{}
	for i := range array {
		if array[i] % 2 == 0 {
			Array = append(Array, array[i])
		} else {
			continue
		}
	} 

	return Array
}
