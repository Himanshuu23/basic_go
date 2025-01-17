package main

import "fmt"

func main() {
	a, b := 1, 2
	fmt.Println(a, b)
	swap(&a, &b)
	fmt.Println(a, b)
}

func swap(x, y *int) {
	 ptr1, ptr2 := x, y
	 temp := *ptr1
	 *ptr1 = *ptr2
	 *ptr2 = temp
}
