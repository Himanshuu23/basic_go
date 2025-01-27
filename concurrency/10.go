package main

import (
	"fmt"
	"sync"
)

var (
	data	int
	mutex	sync.RWMutex
	wg 	sync.WaitGroup
)

func readData(id int) {
	defer wg.Done()
	mutex.RLock()
	fmt.Printf("Data: ", data, id)
	mutex.RUnlock()
}

func writeData(value int) {
	defer wg.Done()
	mutex.Lock()
	data = value
	fmt.Printf("Updated Data: ", value)
	mutex.Unlock()
}

func main() {
	wg.Add(5)

	go readData(1)
	go readData(2)
	go writeData(42)
	go readData(3)
	go readData(4)

	wg.Wait()
}
