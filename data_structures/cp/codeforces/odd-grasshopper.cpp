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
        ll x, n; cin >> x >> n;
        long res(x), s(x % 2 ? 1 : -1);  
        if (n % 4 == 1) res += s * n;
        else if (n % 4 == 2) res -= s;
        else if (n % 4 == 3) res -= s * (n + 1);
    
        cout << res << endl;
    }

    return 0;
}
