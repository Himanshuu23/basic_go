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
        long n, m, i, j; cin >> n >> m >> i >> j;
    
        if ((i <= n / 2 && j <= m / 2) || (i >= n / 2 && j >= m / 2)) cout << "1 " << m << " " << n << " 1\n";
        else cout << "1 1 " << n << " " << m << endl;
    }

    return 0;
}
