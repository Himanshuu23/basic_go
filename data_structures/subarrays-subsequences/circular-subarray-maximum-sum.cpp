#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>& arr, int n) {
    int currSum = 0, maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        currSum = max(arr[i], currSum + arr[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    int totalSum = 0, wrapSum, nonWrapSum = kadane(arr, n);
    
    if (nonWrapSum < 0) { // when all the elements are negative
        return nonWrapSum;
    }

    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
        arr[i] = -arr[i];
    }

    wrapSum = totalSum + kadane(arr, n);
    cout << max(wrapSum, nonWrapSum) << endl;
    
    return 0;
}
