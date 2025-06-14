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
        int n, k; cin >> n >> k;

        if (!(n % 2) || (k == 1))
            cout << "Yes" << endl;

        else if ((n - k) % 2 == 0)
            cout << "Yes" << endl;

        else 
            cout << "No" << endl;
    }

    return 0;
}
