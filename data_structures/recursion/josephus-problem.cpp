/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, int k) {
    if (n == 1) return 0;
    return (solve(n - 1, k) + k) % n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        cout << solve(n, k) + 1 << endl;
    }

    return 0;
}
