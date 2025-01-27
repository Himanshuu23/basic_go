package main

import (
    "fmt"
    "time"
)

func main(){
    ch1 := make(chan string)
    ch2 := make(chan string)

    go send(ch1, "message to the channel 1", 1)
    go send(ch2, "message to the channel 2", 2)

    for i := 1; i <=15; i++ {
        fmt.Println(<-ch1)
        fmt.Println(<-ch2)
    }
}

func send(c chan string, message string, amt time.Duration) {
    for i := 1; i <= 15; i++ {
        c <- message
        time.Sleep(time.Second * amt)
    }
}
