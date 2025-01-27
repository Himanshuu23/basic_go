package main

import (
	"fmt"
)

func main() {
	producer := make(chan int, 20)
	consumer := make(chan int, 20)

	for i := 1; i <= 20; i++ {
		producer <- i
	}

	producer.Close()

	worker(producer, consumer)
	
	go func() {
		fmt.println(<-consumer)
	}()
	
	go func() {
		fmt.println(<-consumer)
	}()

	consumer.Close()
}

func worker(producer <-chan int, consumer<- chan int) {
	for i := range producer {
		consumer <- i
	}
}
