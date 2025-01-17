package main

import "fmt"

func main() {
	Array := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	fmt.Println(Array)

	Transpose(&Array)
	fmt.Println(Array)
}

func Transpose(Array *[][]int) {
	for i := range *Array {
		for j := i + 1; j < len((*Array)[i]); j++ {
			(*Array)[i][j], (*Array)[j][i] = (*Array)[j][i], (*Array)[i][j]		
		}
	}
}
