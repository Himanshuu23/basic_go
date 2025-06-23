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
        int two = 0, three = 0;
        while (n % 2 == 0) { ++two; n /= 2; }
        while (n % 3 == 0) { ++three; n /= 3; }
        if (n != 1 || two > three) cout << "-1\n";
        else cout << 2 * three - two << "\n";
    }

    return 0;
}
