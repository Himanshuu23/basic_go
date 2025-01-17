package main

import "fmt"

type Person struct {
	name 	string
	age	int
}

func (p *Person) Change_info() {
	p.name = "someone"
	p.age = 21
}

func main() {
	var p Person
	
	(&p).Change_info()
	fmt.Println(p)
}
