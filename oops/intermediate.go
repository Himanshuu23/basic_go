package main

import "fmt"

type Rectangle struct {
	length		int
	width		int
}

func (r *Rectangle) Area() int {
	return r.length * r.width
}

func main() {
	r := Rectangle{2, 3}
	fmt.Println(r.Area())
}
