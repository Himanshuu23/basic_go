package main

import (
    "fmt"
    "sync"
)

func main() {
    channel := make(chan int, 5)
    var wg sync.WaitGroup
    
    wg.Add(10)
    for i := 1; i <= 10; i++ {
        go func(value int) {
            defer wg.Done()
            fmt.Println(value, " Worker")
            channel<-i
            fmt.Println(<-channel)
        }(i)
    }
    
    wg.Wait()
}
