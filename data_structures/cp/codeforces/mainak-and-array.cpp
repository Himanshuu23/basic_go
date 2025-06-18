/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll ans = a[n-1] - a[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, a[i] - a[0]);
        }

        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, a[n-1] - a[i]);
        }
        
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, a[i] - a[i+1]);
        }

        cout << ans << endl;
    }

    return 0;
}
