/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> &v, int k) {
    vector<int> dp = v;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        if (!dq.empty()) dp[i] += max(0, dp[dq.front()]);
        while (!dq.empty() && dp[i] >= dp[dq.back()]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n, v, k) << endl;
    }

    return 0;
}
