package main

import (
	"sync"
    "fmt"
)

func main() {
    var mu sync.Mutex
    var wg sync.WaitGroup
	var number int

    mu.Lock()
    Add(&number)
    mu.Unlock()
    
    for i := 1; i <= 2; i++ {
        wg.Add(1)
        go func() {
            defer wg.Done()
            mu.Lock()
            Add(&number)
            mu.Unlock()
        }()
    }
    
    wg.Wait()
}

func Add(num *int) {
    fmt.Println("before incrementing", *num)
	*num++
	fmt.Println("after incrementing", *num)
}
