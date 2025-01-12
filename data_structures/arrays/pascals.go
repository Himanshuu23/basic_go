package main

import "fmt"

func main() {
	Array := pascal(3)
	print2d(Array)
}

func pascal(rows int) [][]int {
	array := [][]int{}
	for i := 0; i <= rows - 1; i++ {
		for j := 0; j <= i; j++ {
			if i == 0 || i == rows - 1 {
				array[i][j] = 0
			} else {
				array[i][j] = array[i-1][j] + array[i-1][j+1]
			}
		}
	}

	return array
}

func print2d(array [][]int) {
	for i := range array {
		for j := range array {
			fmt.Print(array[i][j])
		}
		fmt.Println("\n")
	}
}
