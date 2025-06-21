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
        ll n, t, c1(0), c2(0); cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> t;
            if (t == 0) c1++;
            else if (t == 1) c2++;
        }
        cout << (1LL << c1) * c2 << endl;
    }

    return 0;
}
