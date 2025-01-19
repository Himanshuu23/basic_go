package main

import "fmt"

type Animal interface {
	Speak()		string
}

type Dog struct {}
type Cat struct {}
type Cow struct {}

func (d Dog) Speak() string {
	return "Bark"
}

func (c Cat) Speak() string {
	return "Meow"
}

func (c Cow) Speak() string {
	return "Moo"
}

func Speak(a Animal) {
	fmt.Println(a.Speak())
}

func main() {
	d := Dog{}
	c := Cat{}
	co := Cow{}

	Speak(d)
	Speak(c)
	Speak(co)
}
