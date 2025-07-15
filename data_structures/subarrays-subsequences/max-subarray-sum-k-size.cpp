/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const vector<int>& v, int n, int k) {
    if (n < k) return -1;
    int mx(0), window(0);
    for (int i = 0; i < k; i++) window += v[i];
    mx = window;
    for (int i = k; i < n; i++) {
        window += v[i] - v[i-k];
        mx = max(mx, window);
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(v, n, k) << endl;
    }

    return 0;
}
