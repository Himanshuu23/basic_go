/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> &v) {
    vector<int>dp = v;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < i; j++)
            if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + v[i]);
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n, v) << endl;
    }

    return 0;
}
