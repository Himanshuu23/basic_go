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
        ll n, x, sum1(0), sum2(0); cin >> n >> x;
        vector<int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i]; sum1 += v[i]; sum2 += (v[i] + x - 1) / x;
        }

        cout << (sum1 + x - 1) / x << " " << sum2 << endl;
    }

    return 0;
}
