package main

import "fmt"

func main() {
	a := 2
	fmt.Println(a)

	add(&a)
	fmt.Println(a)
}

func add(x *int) {
	*x += 1
}
