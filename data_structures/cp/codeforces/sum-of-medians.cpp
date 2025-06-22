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
        ll n, k; cin >> n >> k;
        ll a = k * ((n - 1) / 2);
        ll b = 1 + n / 2;
        ll ans(0);
        for (int i = 0; i < n * k; i++) {
            ll temp; cin >> temp;
            if (i < a) continue;
            else if ((i - a) % b == 0) ans += temp;
        }

        cout << ans << endl;
    }

    return 0;
}
