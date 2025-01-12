package main

import "fmt"

func main() {
	Array := []int{1, 1, 2, 3, 4, 5, 5, 6}
	duplicate := duplicates(Array)
	fmt.Println(duplicate)
}

func duplicates(array []int) []int {
	nums := make(map[int]int)
	result := []int{}

	for _, value := range array {
		nums[value]++
	}

	for value := range nums {
		if nums[value] > 1 {
			result = append(result, value)
		}
	}

	return result
}
