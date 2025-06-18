/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b) { return (b == 0) ? a : gcd(b, a%b); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        long n; cin >> n;
        long g(0);
        for (int i = 1; i <= n; i++) {
            long x; cin >> x;
            long diff = i - x;
            diff = (diff > 0) ? diff : -diff;
            g = gcd(g, diff);
        }

        cout << g << endl;
    }

    return 0;
}
