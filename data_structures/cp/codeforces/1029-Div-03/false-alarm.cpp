/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, x;

    cin >> t;

    while(t--) {
        cin >> n >> x;

        vector<int> d;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            d.push_back(temp);
        }

        int s = x;
        for (int i = 0; i < n; i++) {
            if (d[i] == 0 && s == x) {
                continue;
            } else if ((i == (n - 1)) && d[i] == 0) {
                continue;
            } else if (d[i] == 0 && s < x) {
                s--;
            } else if (d[i] == 1) {
                s--;
            }         
        }

        if (s < 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
