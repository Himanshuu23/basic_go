package main

import "fmt"

func main() {
	array := []int{1, 2, 3, 4, 5, 6}
	New := remove(array, 1)
	fmt.Println(New)
}

func remove(array int[], index int) []int {
	Array := append(array[:index], array[index+1:]...)
	return Array
}

//func even(array []int) []int {
//	for 
//}
