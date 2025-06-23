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
        vector<ll>v(n);
        int a = -1, b = -1, c = -1;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 1; i < n - 1; i++) {
            if (v[i-1] < v[i]) {
                if (v[i] > v[i+1]) {
                    a = i;
                    b = i + 1;
                    c = i + 2;
                }
            }
        }

        if ((a != b && b != c) && (a != -1)) {
            cout << "Yes\n" << a << " " << b << " " << c << "\n";
        } else cout << "No\n";
    }

    return 0;
}
