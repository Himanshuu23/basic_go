package main

import (
	"fmt"
	"sync"
)

func main() {
	a := 4
	fmt.Println(a)
	go add(&a)
	fmt.Println(a)
	go subtract(&a)
	fmt.Println(a)
}

func add(x *int) {
	var mu sync.Mutex
	mu.Lock()
	*x += 1
	mu.Unlock()
}

func subtract(x *int) {
	var mu sync.Mutex
	mu.Lock()
	*x -= 1
	mu.Unlock()
}
