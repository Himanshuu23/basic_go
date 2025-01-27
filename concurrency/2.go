package main

import (
	"fmt"
	"sync"
	"runtime"
)

func getGoroutineId() {
	var buf [64]byte

	n := runtime.Stack(buf[:], false)
	id := 0
	fmt.Sscanf(string(buf[:n]), "goroutine %d", &id)
	fmt.Println(id)
}

func main() {
	var wg sync.WaitGroup

	wg.Add(3)

	go func() {
		getGoroutineId()
		wg.Done()
	}()
	
	go func() {
		getGoroutineId()
		wg.Done()
	}()
	
	go func() {
		getGoroutineId()
		wg.Done()
	}()

	wg.Wait()
}
