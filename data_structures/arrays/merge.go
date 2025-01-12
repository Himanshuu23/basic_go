package main

import "fmt"

func main() {
    array := merge()
    fmt.Println(array)
}

func merge() []int {
    Array := []int{1, 2, 3, 4, 5}
    Array = append(Array, []int{0, 1, 1, 1, 1, 0}...)
    return Array
}
