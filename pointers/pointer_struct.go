package main

import "fmt"

type Rectangle struct {
	length	int
	width	int
}

func (r *Rectangle) Perimeter() int {
	return 2*(r.length + r.width)
}

func (r *Rectangle) Area() int {
	return r.length * r.width
}

func main() {
	rect := Rectangle{2, 3}
	fmt.Println(rect, rect.Perimeter(), rect.Area())
}
