/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(int n, int k) {
    return n & (1 << k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        puts(solve(n, k) ? "Yes" : "No" );
    }

    return 0;
}
