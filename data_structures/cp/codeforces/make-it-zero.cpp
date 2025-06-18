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
        int n; cin >> n;
        long ans(0);
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
        }

        if (n % 2) {
            cout << 4 << endl;
            cout << 2 << " " << n << endl;
            cout << 2 << " " << n << endl;
            cout << 1 << " " << 2 << endl;
            cout << 1 << " " << 2 << endl;
        } else {
            cout << 2 << endl;
            cout << 1 << " " << n << endl;
            cout << 1 << " " << n << endl;
        }
    
    }

    return 0;
}
