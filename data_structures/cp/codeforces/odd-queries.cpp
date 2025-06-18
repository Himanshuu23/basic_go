/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        ll n, q, sum = 0; cin >> n >> q;
        ll a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i]; sum += a[i]; a[i] = sum;
        }
        
        int l, r, k;
        while (q--) {
            cin >> l >> r >> k;
            puts((sum - (a[r-1] - (l > 1 ? a[l-2] : 0)) + (r - l + 1) * k) % 2 ? "Yes" : "No"); 
        }
    }

    return 0;
}
