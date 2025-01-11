package main 

import "fmt"

func main() {
	var Array [5]string
	
	fmt.Println("Enter the elements of the array: ")

	for i := range Array {
		fmt.Scanln(&Array[i])
	}

	fmt.Println(Array)
}
