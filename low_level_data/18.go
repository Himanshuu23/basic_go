package main

import (
    "fmt"
)

func main() {
    array, result := []byte{100, 150, 200, 250, 50}, 0
    
    for _, i := range array {
        result += int(i)
    }
    
    fmt.Print(result % 256)
}
