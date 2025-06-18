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
        ll ans(1);
        for (ll i = 2; !(n % i) && (i <= n); i++) { ++ans; }
        cout << ans << endl;
    }

    return 0;
}
