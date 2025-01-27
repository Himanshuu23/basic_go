package main

import (
	"fmt"
	"time"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	
	wg.Add(2)
	
	go func() {
	    Print()
	    wg.Done()
	}()
	go func() {
	    Print()
	    wg.Done()
	}()
	
	Print()
	
	wg.Wait()
}

func Print() {
	for i := 0; i < 10; i++ {
		fmt.Println(i)
	    time.Sleep(time.Millisecond * 500)
	}
}
