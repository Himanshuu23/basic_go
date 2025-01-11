package main

import "fmt"

type Sum interface {
	int | float64 | string
}

func main() {
	array1 := [5]int{1, 23, 4, 5, 6}	
	array2 := [5]float64{1.3, 23.67, 4.2, 0.5, 6}	
	array3 := [5]string{"this ", "is ", "another ", "string ", "!"}

	sum1 := sum(array1)
	sum2 := sum(array2)
	sum3 := sum(array3)

	fmt.Println(sum1, sum2, sum3)
}

func sum[T Sum](Array [5]T) T {
	var sum T

	for i := range Array {
		sum += Array[i]
	}

	return sum
}
