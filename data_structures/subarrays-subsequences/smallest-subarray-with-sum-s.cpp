/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const vector<int>& v, int n, int s) {
    int ans(INT_MAX), sum(0), start(0);

    for (int end = 0; end < n; end++) {
        sum += v[end];

        while (sum >= s) {
            ans = min(ans, end - start + 1);
            sum -= v[start];
            start++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, s; cin >> n >> s;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(v, n, s) << endl;
    }

    return 0;
}
