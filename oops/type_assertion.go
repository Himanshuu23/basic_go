package main

import "fmt"

func main() {
	var value interface{}

	value = 1
	fmt.Println(value.(int))

	value = "gello world"
	fmt.Println(value.(string))

	if result, ok := value.(int); ok {
		fmt.Println(result)
	} else {
		fmt.Println("Not a int but a string value inside it")
	}
}
