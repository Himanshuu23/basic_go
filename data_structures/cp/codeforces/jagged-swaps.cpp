/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n; cin >> t;

    while (t--) {
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            a.push_back(temp);
        }

        if (a[0] == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
