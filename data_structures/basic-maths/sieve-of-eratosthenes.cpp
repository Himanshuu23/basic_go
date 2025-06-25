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
        vector<int> v(n);
        for (int i = 2; i <= n; i++) {
            if (v[i] == 0) {
                for (int j = i * i; j <= n; j += i) {
                    v[j] = 1;
                }
            }
        }
        for (int i = 2; i <= n; i++) if (v[i] == 0) cout << i << endl;
        cout << endl;
    }

    return 0;
}
