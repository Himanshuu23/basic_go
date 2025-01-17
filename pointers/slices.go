package main

import "fmt"

func main() {
	slice := []int{1, 2, 3, 4}
	fmt.Println(slice)
	var ptr *[]int = &slice

	*ptr = append(*ptr, 1, 2, 3, 4)
	
	fmt.Println(slice)
}
