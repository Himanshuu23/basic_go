package main

import "fmt"

func main() {
    Array := []int{1, 2, 3, 4, 5}
    fmt.Println(binarySearch(Array, 0, len(Array), 5))
    fmt.Println(binarySearch(Array, 0, len(Array), 6))
}

func binarySearch(array []int, start, end, target int) int {
    if start > end {
        return -1
    }

    mid := (start + end) / 2

    if mid == len(array) {
        return -1
    } else if (array[mid] == target) {
        return mid
    } else if (target < array[mid]) {
        return binarySearch(array, start, mid - 1, target)
    } else if (target > array[mid]){
        return binarySearch(array, mid + 1, end, target)
    }

    return -1
}
