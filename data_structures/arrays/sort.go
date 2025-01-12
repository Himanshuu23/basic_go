package main

import "fmt"

func main() {
    array := []int{2, 1, 5, -2}
    sorted := sort(array)
    fmt.Println(sorted)
}

func sort(array []int) []int {
    for i := range len(array) {
        for j := 0; j <= len(array) - i; j++ {
            bubble := array[0]
            if array[j] < bubble {
                bubble = array[j]
            }
        }
    }

    return array
}
