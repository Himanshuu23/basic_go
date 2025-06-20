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
        ll n, mx, mn; cin >> n;
        
        if (n % 2 || n < 4) cout << -1 << endl;
        else {
            mn = n / 6;
            if (n % 6) mn++;
            mx = n / 4;
            cout << mn << " " << mx << endl;
        }
    }

    return 0;
}
