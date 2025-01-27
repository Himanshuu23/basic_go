package main

import (
    "fmt"
    "time"
)

func main() {
    channel := make(chan string)

    go func() {
        channel <- "sending this to the channel"
    }()

    time.Sleep(time.Second * 1)

    fmt.Println(<-channel)
}
