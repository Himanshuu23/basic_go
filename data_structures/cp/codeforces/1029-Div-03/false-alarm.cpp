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

        int i = 0;
        for ( ; i < n; i++) {
            int temp = 0; cin >> temp;
            d.push_back(temp);
        }

        int cnt = 0;
        i = 0;

        while (i < n) {
            if (d[i] == 1) {
                cnt += 1;
                i += x;
            } else {
                i++;
            }
        }

        if (cnt <= 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
