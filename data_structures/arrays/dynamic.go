package main

import "fmt"

func main() {
    Array, i := []int{}, 0
    fmt.Println("Starting Entering...")
    for {
        fmt.Scanln(&i)
        if i == -1 {
            break    
        } else {
            Array = append(Array, i)
        }
    }
    fmt.Println(Array)
}
