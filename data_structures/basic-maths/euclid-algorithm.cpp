/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return (a == 0) ? b : gcd(b, a % b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll a, b; cin >> a >> b;
        cout << gcd(a, b) << '\n';
    }

    return 0;
}
