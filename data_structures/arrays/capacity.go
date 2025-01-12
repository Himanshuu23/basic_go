package main

import "fmt"

func main() {
	Array := make([]int, 2, 4)
	Array = append(Array, 1, 2, 3)
	fmt.Println(len(Array), cap(Array))
}
