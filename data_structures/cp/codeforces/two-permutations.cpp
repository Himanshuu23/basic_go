/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while(t--) {
        long n, a, b; cin >> n >> a >> b;
        bool res = (a == n && b == n ) || (a + b + 1 < n);
        if (res)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }

    return 0;
}
