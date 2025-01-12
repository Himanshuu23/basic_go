package main

import "fmt"

func main() {
	Array := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	rotate(Array)
}

func rotate(array [][]int) {
	for i := range array {
		for j := len(array) - 1; j >= 0; j-- {
			fmt.Print(array[j][i], " ")
		}
		
		fmt.Println("\n")
	}
}
