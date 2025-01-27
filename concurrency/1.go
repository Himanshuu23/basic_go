package main

import (
	"fmt"
)

func main() {
	Print()
	go Print()	
}

func Print() {
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	}
}
