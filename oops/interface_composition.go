package main

import "fmt"

type Shape interface {
	Area() 		int
}

type Movable interface {
	Move()		bool
}

type Car struct {
	side 		int
	canMove		bool
}

func (c Car) Area() int {
	return c.side * c.side
}

func (c Car) Move() bool {
	return c.canMove
}

func Area(s Shape) {
	fmt.Println(s.Area())
}

func Move(m Movable) {
	fmt.Println(m.Move())
}

func main() {
	c := Car{2, false}
	Area(c)
	Move(c)
}
