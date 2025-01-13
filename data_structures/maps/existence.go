package main

import "fmt"

func main() {
	fruits := make(map[string]int)
	var name string

	fruits["mango"] = 100
	fruits["apple"] = 200
	fruits["guava"] = 300
	fruits["kiwi"] = 400

	fmt.Println("Enter the name of the fruit whose price you wanna know: ")
	fmt.Scanln(&name)

	if _, found := fruits[name]; found {
		fmt.Println(name, "->", fruits[name])
	} else {
		fmt.Println("Not found")
	}
}
