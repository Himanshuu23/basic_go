/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxProduct(vector<int> &v, int n) {
    int mx = v[0], mn = v[0], ans = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] < 0) swap(mx, mn);
        mx = max(v[i], v[i]*mx);
        mn = min(v[i], v[i]*mn);
        ans = max(ans, mx);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << maxProduct(v, n) << endl;
    }

    return 0;
}
