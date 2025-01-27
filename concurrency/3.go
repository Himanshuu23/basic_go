package main

import (
	"fmt"
	"sync"
)

func main() {
	buf := make(chan int)
	unbuf := make(chan int, 3)

	unbuf <- 1
	unbuf <- 2
	unbuf <- 3

	go func() {
		buf<-33	
	}()

	go func() {
		ch <- 4
	}()

	fmt.Println(<-buf)
	fmt.Println(<-unbuf)
	fmt.Println(<-unbuf)
	fmt.Println(<-unbuf)
}
