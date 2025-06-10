/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n % k)
            cout << 1 << endl << n << endl;
        else
            cout << 2 << endl << n - 1 << " " << 1 << endl;     
    }

    return 0;
}
