/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ways(int n) {
    if (n == 0 || n == 1) return n;
    return ways(n - 1) + ways(n - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << ways(n) << endl;
    }

    return 0;
}
