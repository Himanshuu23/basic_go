package main

import "fmt"

func main() {
	array := []int{1, 2, 34, 5, 6, 4, 94}
	
	biggest := largest(array)
	fmt.Println(biggest)
}

func largest(array []int) int {
	bigboi := array[0]
	for i := range len(array) {
		if array[i] > bigboi {
			bigboi = array[i]
		}
	}

	return bigboi
}
