/*
Given an integer array nums, find a peak element, and return its index. A peak element is an element that is strictly greater than its neighbors.
You may imagine that nums[-1] = -∞ and nums[n] = -∞.
You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index 1 (element 2) or index 5 (element 6) as both are peak elements.

Constraints:
    1 <= nums.length <= 1000
    -2^31 <= nums[i] <= 2^31 - 1
    nums[i] ≠ nums[i + 1] for all valid i
*/

package main
import "fmt"

func main() {
    array := []int{1, 2, 3, 1}
    fmt.Println(peakElement(array))
}

func peakElement(array []int) int {
    start, end := 1, len(array) - 1 // since first & last elements can never be the required solution so excluding them in the search

    if len(array) == 1 {
        return 0
    }

    for start <= end {
        mid := (start + end) / 2

        if ((array[mid] > array[mid+1]) && (array[mid-1] < array[mid])) {
            return mid
        } else if (array[mid+1] > array[mid]) {
            start++
        } else {
            end--
        }
    }

    return -1
}
