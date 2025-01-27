package main

import (
    "fmt"
    "sync"
)

func main(){
    chan1 := make(chan int, 10)
    chan2 := make(chan int, 10)
    chan3 := make(chan int, 10)

    var wg1 sync.WaitGroup
    var wg2 sync.WaitGroup
    
    wg1.Add(1)
    
    go work1(chan1, chan2, &wg1)
    
    for i := 1; i <= 10; i++ {
        chan1 <- i
    }
    
    close(chan1)
    wg1.Wait()
    wg2.Add(1)
    close(chan2)
    
    go work2(chan2, chan3, &wg2)
    
    wg2.Wait()
    
    close(chan3)
    for i := range chan3 {
        fmt.Println(i)
    }
}

func work1(chan1 <-chan int, chan2 chan int, wg *sync.WaitGroup) {
    for i := range chan1 {
        chan2 <- i
    }
    wg.Done()
}

func work2(chan2 chan int, chan3 chan<- int, wg *sync.WaitGroup) {
    for i := range chan2 {
        chan3 <- square(i)
    }
    wg.Done()
}

func square(num int) int {
    return num*num
}
