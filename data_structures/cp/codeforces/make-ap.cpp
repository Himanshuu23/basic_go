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
        long a, b, c; cin >> a >> b >> c;
        bool res = ((2 * b > c) && ((2 * b - c) % a == 0)) || ((2 * b > a) && ((2 * b - a) % c == 0)) || ((a + c) % (2 * b) == 0);       
        puts(res ? "Yes" : "No");
    }

    return 0;
}
