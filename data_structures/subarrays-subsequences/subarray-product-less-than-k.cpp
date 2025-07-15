/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const vector<int>& v, int n, int k) {
    int start(0), ans(0), product(1);

    for (int end = 0; end < n; end++) {
        product *= v[end];

        while (product >= k) {
            product /= v[start];
            start++;
        }

        ans += end - start + 1;
    }

    return ans;
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
