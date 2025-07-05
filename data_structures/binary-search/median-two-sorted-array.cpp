#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();
    int start = 0, end = m;

    while (start <= end) {
        int partitionX = (start + end) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX; // cutting the nums1 in a way that left cut of nums1 gets the median and also all elements on left are less than the right ones

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1]; // last element on left side of nums1
        int minRightX = (partitionX == m) ? INT_MAX : nums1[partitionX]; // first element on right side of nums1

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1]; // last element on left side of nums2
        int minRightY = (partitionY == n) ? INT_MAX : nums2[partitionY]; // first element on right side of nums2

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) { // finding the correct size of right half for the partitioned nums1 by partitioning nums2 using partitionY - we want biggest on left <= smallest on right -> correct condition for calculation of median
            if ((m + n) % 2 == 0)
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            else
                return max(maxLeftX, maxLeftY);
        } else if (maxLeftX > minRightY) {
            end = partitionX - 1;
        } else {
            start = partitionX + 1;
        }
    }

    return -1.0;
}

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    cout << findMedianSortedArrays(nums1, nums2) << endl;
}

