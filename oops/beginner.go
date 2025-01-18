package main

import "fmt"

type Car struct {
	model	string
	year 	string
}

func main() {
	A := Car{"a", "2020"}
	fmt.Println(A)
}
