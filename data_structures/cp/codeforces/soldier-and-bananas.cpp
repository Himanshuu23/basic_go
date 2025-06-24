/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k, n, w, ans(0); cin >> k >> n >> w;
    for (long i = 1; i <= w; i++) ans += k * i;
    cout << max(ll(0), ans - n) << endl;
    return 0;
}
