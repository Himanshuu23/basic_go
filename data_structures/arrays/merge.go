package main

import "fmt"

type ArrayItem interface {
    int | float64 | string 
}

func main() {
    array := merge()
    fmt.Println(array)
}

func merge[T ArrayItem]() []T {
    Array := []T{1, 2, 3, 4, 5}
    Array = append(Array, []T{0, 1, 1, 1, 1, 0}...)
    return Array
}
