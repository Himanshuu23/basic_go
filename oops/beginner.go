package main

import "fmt"

type Car struct {
	model	string
	year 	string
}

type Circle struct {
	radius	float64
}

func (c Circle) Area() float64 {
	return c.radius * c.radius * 3.14
}

func main() {
	A := Car{"a", "2020"}
	fmt.Println(A)
	A.model = "b"
	fmt.Println(A)
	Print(A)
	newCar := struct {
		model string
		year  string
	}{
		model: "something",
		year:  "something-else",
	}

	c := Circle{3}
	fmt.Println(c.Area())

	Print(newCar)
}

func Print(car Car) {
	fmt.Println(car.model, car.year)
}
