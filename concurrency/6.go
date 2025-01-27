package main

import (
	"sync"
	"fmt"
)

func main() {
	var mut sync.Mutex
	var number int

	go Add(&number)
	go Add(&number)
}

func Add(num *int) {
	*int++
}
