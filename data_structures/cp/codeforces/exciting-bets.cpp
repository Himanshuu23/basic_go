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
        ll a, b; cin >> a >> b;
        ll diff = abs(a - b);
        if (a > b) cout << diff << " " << min(diff - (a % diff), b % diff) << endl;
        else if (b > a) cout << diff << " " << min(diff - (b % diff), a % diff) << endl;
        else cout << 0 << " " << 0 << endl;
    }

    return 0;
}
