package main

import (
	"fmt"
	"sync"
)

func main() {
    var wg sync.WaitGroup
	producer := make(chan int, 20)
	consumer := make(chan int, 20)

    wg.Add(2)

    go worker(producer, consumer, &wg)
    go worker(producer, consumer, &wg)
    
	for i := 1; i <= 20; i++ {
		producer <- i
	}

	close(producer)

    wg.Wait()
    close(consumer)
    
    for i := range consumer{
	   fmt.Println(i)
	}
}

func worker(producer <-chan int, consumer chan<- int, wg *sync.WaitGroup) {
	defer wg.Done()
	for i := range producer {
		consumer <- i
	}
}
