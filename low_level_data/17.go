package main

import (
    "fmt"
)

func main() {
    count, num1, num2 := 0, 5, 4
    binary1 := fmt.Sprintf("%b", num1)
    binary2 := fmt.Sprintf("%b", num2)
    
    for i := range binary1 {
        if string(binary1[i]) == string(binary2[i]) {
            continue
        } else {
            count++
        }
    }
    
    fmt.Print(count)
}
