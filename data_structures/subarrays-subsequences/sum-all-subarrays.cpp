#include <bits/stdc++.h>
using namespace std;

/*
For an array arr of length n, each element arr[i] contributes to multiple subarrays. Specifically, it appears in (i + 1) * (n - i) subarrays.
*/

int main() {
    int n; cin >> n;
    vector<int> arr;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        arr.push_back(temp);
    }

    for (int j = 0; j < n; j++) {
        sum += arr[j] * (j + 1) * (n - j);
    }

    cout << sum << endl;
    return 0;
}
