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
        ll n, div; cin >> n; div = n / 2;
        puts(n & (n - 1) ? "Yes" : "No");
    }

    return 0;
}
