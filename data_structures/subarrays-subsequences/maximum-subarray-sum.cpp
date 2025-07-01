#include <bits/stdc++.h>
using namespace std;

int cumulative(vector<int>& arr, int n) { // O(n²)
    vector<int> currSum(n+1);
    currSum[0] = 0;

    for (int i = 1; i <= n; i++) {
        currSum[i] = currSum[i-1] + arr[i-1];
    }

    int maxSum = INT_MIN;

    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }

    return maxSum;
}

int kadane(vector<int>& arr, int n) { // O(n)
    int currSum = arr[0], maxSum = a[0];
    
    for (int i = 1; i < n; i++) {
        currSum = max(arr[i], arr[i] + currSum);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

int main() {
    int n; cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        v.push_back(temp);
    }

    cout << cumulative(v, n) << endl;
    cout << kadane(v, n) << endl;
}
