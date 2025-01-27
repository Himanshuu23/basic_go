package main

import (
	"fmt"
	"sync"
	"time"
)

func main() {
	channel := make(chan int, 2)
	var wg sync.WaitGroup

	ticker := time.NewTicker(2 * time.Second)
	defer ticker.Stop()

	wg.Add(10)
	for i := 1; i <= 10; i++ {
		go func(value int) {
			defer wg.Done()
			channel <- value
		}(i)
	}

	go func() {
		for {
			select {
			case <-ticker.C:
				for i := 0; i < 2; i++ {
					select {
					case req := <-channel:
						fmt.Println("Processing request:", req)
					default:
						fmt.Println("No more requests to process")
						return
					}
				}
			}
		}
	}()

	wg.Wait()
}
