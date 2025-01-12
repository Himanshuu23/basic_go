package main

import "fmt"

func main() {
    array := []int{2, 1, 5, -2}
    sorted := sort(array)
    fmt.Println(sorted)
}

func sort(array []int) []int {
    for i := range array {
        for j := 0; j < len(array) - i -1; j++ {
            if array[j] > array[j+1] {
                array[j], array[j+1] = array[j+1], array[j]
            }
        }
    }

    return array
}
