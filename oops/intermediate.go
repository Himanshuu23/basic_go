package main

import "fmt"

type Shape interface {
	Perimeter()	float64
}

type Circle struct {
	radius 	float64
}

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

func (r Rectangle) Perimeter() float64 {
	return float64(2 * (r.length + r.width))
}

func (c Circle) Perimeter() float64 {
	return 3.14 * c.radius * c.radius
}

func Perimeter(s Shape) {
	fmt.Println(s.Perimeter())
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

func (r Rectangle) Display() {
	fmt.Println(r.length, r.width)
}

func (c Circle) Display() {
	fmt.Println(c.radius)
}

func main() {
	r := NewRectangle(2, 3)
	fmt.Println(r.Area())

	c := Circle{2}

	a := Dog{name: "Shanky", Animal: Animal{sound: "bark"}}

	a.PrintSound()
	Perimeter(*r)
	Perimeter(c)

	r.Display()
	c.Display()
}
