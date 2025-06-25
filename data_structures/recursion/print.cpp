/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void inc(ll n) {
    if (n == 0) return;
    inc(n - 1);
    cout << n << " ";
}

void dec(ll n) {
    if (n == 0) return;
    cout << n << " ";
    dec(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        inc(n);
        dec(n);
    }

    return 0;
}
