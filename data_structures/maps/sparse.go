package main

import "fmt"

func main() {
	var row, col int

	fmt.Println("Enter the number of rows")
	fmt.Scanln(&row)
	fmt.Println("Enter the number of columns")
	fmt.Scanln(&col)
	
	Map := make(map[[2]int]int)
	Array := make([][]int, row)
	Matrix1 := [][]int{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}
	Matrix2 := [][]int{
		{10, 11, 12},
		{13, 14, 15},
		{16, 17, 18},
	}

	for i := range row {
		Array[i] = make([]int, col)
		for j := range col {
			Array[i][j] = 0
		}
	}

	for i := range row {
		for j := range col {
			fmt.Scanln(&Array[i][j])
			if Array[i][j] != 0 {
				Map[[2]int{ i, j }] = Array[i][j]
			}
		}
	}

	Print(Array)
	add(Matrix1, Matrix2)
	multiply(Matrix1, Matrix2)
}

func add(Array1, Array2 [][]int) {
	for i := range Array1 {
		for j := range Array2 {
			fmt.Print(Array1[i][j] + Array2[i][j])	
		}
	}
}

func multiply(Array1, Array2 [][]int) {
	for i := range Array1 {
		result := 0
		for j := range Array2 {
			result += Array1[i][j]*Array2[j][i] 
		}
		fmt.Println(result)
	}
}

func Print(Array [][]int) {
	for i := range Array {
		for j := range Array[i] {
			fmt.Println(Array[i][j], " ")
		}
		fmt.Println("\n")
	}
}
