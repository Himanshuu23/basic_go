package main

import (
    "fmt"
    "time"
)

func main() {
    chan1 := make(chan string, 10)
    chan2 := make(chan int, 10)
    
    go send1(chan1, "message")
    go send2(chan2, 69)
    
    for i := 1; i <= 20; i++ {
        select {
            case x := <-chan1: {
                fmt.Println(x)
            }
            case y := <-chan2: {
                fmt.Println(y)
            }
        }
    }
}

func send1(c chan string , message string) {
    for i := 1; i <= 10; i++ {
        c<-message
        time.Sleep(time.Second * 1)
    }
}

func send2(c chan int , message int) {
    for i := 1; i <= 10; i++ {
        c<-message
        time.Sleep(time.Second * 2)
    }
}
