/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pairs(ll n) {
    if (n == 0 || n == 1) return n;
    return pairs(n-1) + pairs(n - 2) * (n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << pairs(n) << endl;
    }

    return 0;
}
