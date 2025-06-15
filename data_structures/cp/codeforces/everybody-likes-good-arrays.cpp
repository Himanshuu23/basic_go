/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> v;

        for (int i = 0; i < n; i++) {
            int temp = 0; cin >> temp;
            v.push_back(temp);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if ((v[i] & 1) && (v[i+1] & 1))
                ans++;
            if (!(v[i] & 1) && !(v[i+1] & 1))
                ans++;
        }

        cout << ans << endl;
    }

    return 0;
}
