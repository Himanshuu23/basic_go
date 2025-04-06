/*
You are a product manager leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous one, all versions after a bad version are also bad.

You are given an API:
func isBadVersion(version int) bool which returns whether the version is bad.

Your task is to find the first bad version out of n versions.
You must:
    - Minimize the number of calls to isBadVersion.
    - Return the lowest version number that is bad.

Example:

n = 5, bad = 4

isBadVersion(3) → false  
isBadVersion(4) → true  
isBadVersion(5) → true

Output: 4
*/

package main

import "fmt"
    
func main() {    
    fmt.Println(firstBadVersion(5))
}

func isBadVersion(n int) bool {
    BAD := 4
    return n >= BAD
}

func firstBadVersion(n int) int {
    start, end := 0, n

    for start < end {
        mid := (start + end) / 2

        if isBadVersion(mid) {
            end = mid
        } else {
            start = mid + 1
        }
    }

    return start
}
