package main

import "fmt"

func main() {
	array := []int{1, 2 ,3, 4, 5, 6, 7, 8, 9, 10}
	Array := make([]int, 2, 4)
	Array = append(Array, 1, 2, 3)
	Array = array[:]
	fmt.Println(len(Array), cap(Array))
}
