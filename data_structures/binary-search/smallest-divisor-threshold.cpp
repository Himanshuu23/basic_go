#include <bits/stdc++.h>
using namespace std;

int divideArray(vector<int>& nums, int divisor) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += ceil((double)nums[i] / divisor);
    }
    return sum;
}

int smallestDivisorThreshold(vector<int>& nums, int threshold) {
    int start = 1, end = *max_element(nums.begin(), nums.end()), ans = -1;

    while (start <= end) {
        int mid = (start + end) / 2;
        int result = divideArray(nums, mid);

        if (result <= threshold) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    return ans;
}
