/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t;

    while(t--) {
        cin >> n;

        vector<int> v;

        int left = 1, right = n;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                v[i] = right;
                --right;
            } else {
                v[i] = left;
                ++left;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
