package main

import "fmt"

func main() {
	array := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	for i := range array {
		for j := range array  {
			fmt.Print(array[i][j], " ")
		}
		
		fmt.Println("\n")
	}
}
