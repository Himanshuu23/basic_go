package main

import "fmt"

type Animal struct {
	sound	string
}

type Dog struct {
	name	string
	Animal
}

type Rectangle struct {
	length		int
	width		int
}

func (a Animal) PrintSound() {
	fmt.Println(a.sound)
}

func NewRectangle(length, width int) *Rectangle {
	return &Rectangle{
		length: length,
		width:  width,
	}
}


func (r *Rectangle) Area() int {
	return r.length * r.width
}

func main() {
	r := NewRectangle(2, 3)
	fmt.Println(r.Area())

	a := Dog{name: "Shanky", Animal: Animal{sound: "bark"}}

	a.PrintSound()
}
