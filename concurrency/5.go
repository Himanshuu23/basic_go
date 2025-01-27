package main

import (
	"fmt"
	"sync"
)

func main(){
	var wg sync.WaitGroup
	fanin := make(chan int, 10)
	fanout := make(chan int, 10)

	wg.Add(1)

	go worker(fanin, fanout, &wg)

	for i := 1; i <= 10; i++ {
		fanin <- i
	}

	close(fanin)
	wg.Wait()
	close(fanout)

	for i := range fanout {
		fmt.Println(i)
	}
}

func worker(fanin <-chan int, fanout chan<- int, wg *sync.WaitGroup){
	defer wg.Done()
	for i := range fanin {
		fanout <- square(i)
	}
}

func square(num int) int {
	return num*num
}
