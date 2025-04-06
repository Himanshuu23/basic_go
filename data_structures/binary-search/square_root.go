/*
Given a non-negative integer x, compute and return the integer part of its square root.
Only return the floor value (i.e., truncate the decimal part).
You must not use any built-in exponent function like sqrt().

Example:

Input: x = 8  
Output: 2  
Explanation: √8 ≈ 2.828... → floor is 2

Goal:

Implement a function:
func mySqrt(x int) int
*/

package main

import "fmt"

func main() {
    fmt.Println(sqrt(8))    
    fmt.Println(sqrt(9))    
}

func sqrt(x int) int {
    start, end := 0, x

    for start <= end {
        mid := (start + end) / 2

        if mid * mid == x {
            return mid
        } else if (mid * mid < x) {
            start = mid + 1
        } else if (mid * mid > x) {
            end = mid - 1
        }
    }
    
    return end
}
