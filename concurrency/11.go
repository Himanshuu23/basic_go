package main

import (
	"fmt"
	"sync/atomic"
	"sync"
)

func main() {
    var wg sync.WaitGroup
	var counter int32 = 0
	
	wg.Add(10)

	for i := 0; i < 10; i++ {
		go func() {
			for j := 0; j < 100; j++ {
				atomic.AddInt32(&counter, 1)
			}
			wg.Done()
		}()
	}

	wg.Wait()

	fmt.Println("Final Counter Value:", atomic.LoadInt32(&counter))
}
