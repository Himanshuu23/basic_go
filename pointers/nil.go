package main

import "fmt"

func main() {
	var number int = 3
	var ptr *int = &number

	if ptr == nil {
		fmt.Println("pointer is null")
	}

	fmt.Println(ptr)
}
