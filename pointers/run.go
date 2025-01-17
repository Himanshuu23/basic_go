package main

import "fmt"

type number int 

func main() {
	num := new(number)
	fmt.Println(num, *num)

	*num = 22
	fmt.Println(num, *num)
}
