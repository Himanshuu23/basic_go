/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;

        vector<int> v;
        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            mp[temp]++;
        }

        if (n == 1 || mp.size() == 1) {
            cout << "Yes" << endl;
            continue;
        }

        if (mp.size() >= 3) {
            cout << "No" << endl;
            continue;
        }

        if (mp.size() == 2) {
            for (auto it: mp) {
                v.push_back(it.second);
            }

            abs(v[0] - v[1]) >= 2 ? cout << "No" << endl : cout << "Yes" << endl;
        }
    }
    return 0;
}
