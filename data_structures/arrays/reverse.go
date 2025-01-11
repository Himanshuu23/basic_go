package main

import "fmt"

type ArrayItems interface {
	int | string | float64
}

func main() {
	Array := []T{}

	Reversed := reverse(Array)
	fmt.Println(Reversed)
}

func reverse[T ArrayItems](array []T) []T {
	reverse := make([]T{})

	for _, item := range array {
		reverse = append(reverse, item)
	}

	return reverse
}
