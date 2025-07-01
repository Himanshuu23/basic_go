/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> &v) {
    int curr(0), currOp(0), mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        int prevCurr = curr;
        curr = max(v[i], v[i] + curr);
        currOp = max(currOp + v[i], prevCurr - v[i] + v[i] * v[i]);
        mx = max({mx, curr, currOp});
    }
    return mx;
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
