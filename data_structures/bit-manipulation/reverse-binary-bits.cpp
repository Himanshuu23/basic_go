/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n) {
    n = (n >> 16) | (n << 16);
    n = (((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8));
    n = (((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4));
    n = (((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2));
    n = (((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1));
    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << bitset<32>(n) << endl;
        cout << bitset<32>(solve(n)) << endl;
    }

    return 0;
}
