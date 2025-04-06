/*
Problem Statement:
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

Example 1:
Input: nums = [1,3,5,6], target = 5 Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2 Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7 Output: 4

Constraints:
    The array is sorted in ascending order.
    The array contains distinct values.
*/

package main

import "fmt"

func main() {
    array := []int{1, 2, 3, 4, 5}

    fmt.Println(searchInsertPosition(array, 4, 0, len(array)))
    fmt.Println(searchInsertPosition(array, 6, 0, len(array)))
    fmt.Println(searchInsertPosition(array, 0, 0, len(array)))
}

func searchInsertPosition(array []int, target, start, end int) int {
    if start > end {
        return start
    }

    mid := (start + end) / 2

    if mid == len(array) {
        return start
    } else if (target == array[mid]) {
        return mid
    } else if (target < array[mid]) {
        return searchInsertPosition(array, target, start, mid - 1)
    } else if (target > array[mid]) {
        return searchInsertPosition(array, target, mid + 1, end)
    }

    return start
}
