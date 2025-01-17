package main

import "fmt"

func main() {
	array := []int{1, 2, 3, 4, 5}

	fmt.Println(array)

	var ptr *int

	for i := range array {
		ptr = &array[i]
		*ptr += 2
	}

	fmt.Println(array)
}
