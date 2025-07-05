/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int m, int k, vector<int>& nums1, vector<int>& nums2) {
    if (n > m) return solve(m, n, k, nums2, nums1);

    int start = max(0, k - m), end = min(k, n);

    while (start <= end) {
        int partitionX = (start + end) / 2;
        int partitionY = k - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == n) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == m) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
            return max(maxLeftX, maxLeftY);
        else if (maxLeftX > minRightY)
            end = partitionX - 1;
        else
            start = partitionX + 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> nums1(n), nums2(m);
        for (int i = 0; i < n; ++i) cin >> nums1[i];
        for (int i = 0; i < m; ++i) cin >> nums2[i];
        cout << solve(n, m, k, nums1, nums2) << '\n';
    }

    return 0;
}
