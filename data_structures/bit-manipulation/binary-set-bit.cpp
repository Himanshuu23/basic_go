/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n) {
    int ct(0);
    while(n) {
        n &= n - 1;
        ct++;
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string bin; cin >> bin;
        int n = stoi(bin);
        cout << solve(n) << endl;
    }

    return 0;
}
