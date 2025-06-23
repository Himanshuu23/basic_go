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
        string s; cin >> s;
        ll z(0), o(0);
        for (long i = 0; i < s.size(); i++) { s[i] == '0' ? ++z : ++o; }
        long x = min(z, o);
        x %= 2;
        puts(x ? "DA" : "NET");
    }

    return 0;
}
