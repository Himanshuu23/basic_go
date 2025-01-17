package main 

import "fmt"

func main() {
	var number int = 3
	var ptr *int = &number
	fmt.Println(number, ptr, *ptr)
	*ptr += 66
	fmt.Println(number, ptr, *ptr)
}
