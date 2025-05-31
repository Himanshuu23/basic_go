/*
You are given a rotated sorted array nums of distinct integers and an integer target.
Return the index of target if it is in nums, or -1 if it is not.

The array was originally sorted in ascending order and then rotated at some unknown pivot.

Constraints
1 <= nums.length <= 10
-10⁴ <= nums[i], target <= 10⁴
All integers in nums are unique.

Input: nums = [4,5,6,7,0,1,2], target = 0  
Output: 4

Input: nums = [4,5,6,7,0,1,2], target = 3  
Output: -1
*/

package main
import "fmt"

func main() {
    nums := []int{ 4, 5, 6, 7, 0, 1, 2 }
    fmt.Println(searchRotatedArray(nums, 0))
    fmt.Println(searchRotatedArray(nums, 3))
}

func searchRotatedArray(nums []int, target int) int {
    start, end := 0, len(nums) - 1

    for start <= end {
        mid := (start + end) / 2

        if (nums[mid] == target) {
            return mid
        } else if (nums[start] <= nums[mid]) {
            if ((nums[start] <= target) && (target <= nums[mid])) {
                end = mid - 1
            } else {
                start = mid + 1
            }
        } else {
            if ((target < nums[end]) && (target > nums[mid])) {
                start = mid + 1
            } else {
                end = mid - 1
            }
        }
    }

    return -1
}
