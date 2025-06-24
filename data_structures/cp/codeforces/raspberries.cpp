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
        int n, k, mod(0), ev(0); cin >> n >> k;
        bool d(false);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x %= k;
            if (x) mod = (mod > x) ? mod : x;
            else d = true;
            if (x == 2) ++ev;
        }

        if (d) cout << "0\n";
        else if (k == 4) {
            if (ev >= 2) cout << "0\n";
            else if (ev >= 1 || mod == 3) cout << "1\n";
            else cout << "2\n";
        }
        else cout << k - mod << endl;
    }

    return 0;
}
