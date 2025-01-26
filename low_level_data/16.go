package main

import (
    "fmt"
)

func main() {
    count, num := 0, 5
    binary := fmt.Sprintf("%b", num)
    
    for _, i := range binary {
        if string(i) == "1" {
            count++
        }
    }
    
    fmt.Print(count)
}
