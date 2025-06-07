/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, k;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        vector<int> v;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            v.push_back(temp);
        }

        bool flag = true;

        for (int i = 0; i < n; i++) {
            if (v[i] == k) {
                cout << "YES" << endl;
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "NO" << endl;
    }

    return 0;
}
