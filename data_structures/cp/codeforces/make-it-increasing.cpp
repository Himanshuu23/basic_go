/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define vi vector<int>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n, ans(0); cin >> n;
        vi a(n);

        for (int i = 0; i < n; i++) scanf("%ld", &a[i]);
        for (int i = n - 2; i >= 0; i--) {
            if (a[i+1] <= 0) { ans = -1; break; }
            while(a[i] >= a[i+1]) { a[i] /= 2; ++ans; }
        }

        cout << ans << endl;
    }

    return 0;
}
