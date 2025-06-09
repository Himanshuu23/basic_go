/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());

        if (v.front() == v.back()) {
            cout << -1 << endl;
            continue;
        }

        int itr = 0;
        while (v[itr] == v[0]) {
            itr++;
        }

        cout << itr << " " << n - itr << endl;

        for (int i = 0; i < itr; i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        for (int i = itr; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
