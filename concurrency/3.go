package main

import (
	"fmt"
)

func main() {
	unbuf := make(chan int)
    buf := make(chan int, 3)

	buf <- 1
	buf <- 2
	buf <- 3

	go func() {
		unbuf<-33	
	}()

	go func() {
		buf <- 4
	}()

	fmt.Println(<-unbuf)
	fmt.Println(<-buf)
	fmt.Println(<-buf)
	fmt.Println(<-buf)
	fmt.Println(<-buf)
}
