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
        long n; cin >> n;
    
        for (int i = 0; i < n; i++) {
            long temp; cin >> temp;

            cout << (n + 1) - temp << " ";
        }
        cout << endl;
    }

    return 0;
}
