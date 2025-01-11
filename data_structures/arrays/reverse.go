package main

import "fmt"

type ArrayItems interface {
	int | string | float64
}

func main() {
	Array := []int{1, 2, 3, 4, 5, 6}

	Reversed := reverse(Array)
	fmt.Println(Reversed)
}

func reverse[T ArrayItems](array []T) []T {
	reverse := []T{}

	for i := len(array) - 1; i >= 0; i-- {
		reverse = append(reverse, array[i])
	}

	return reverse
}
