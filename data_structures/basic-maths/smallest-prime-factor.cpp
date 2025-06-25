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
        ll n; cin >> n;
        vector<int>v(n);
        for (int i = 2; i <= n; i++) v[i] = i;
        for (int i = 2; i <= n; i++) {
            if (v[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (v[j] == j) v[j] = i;
                }
            }
        }
        while(n != 1) {
            cout << v[n] << endl;
            n /= v[n];
        }
    }

    return 0;
}
