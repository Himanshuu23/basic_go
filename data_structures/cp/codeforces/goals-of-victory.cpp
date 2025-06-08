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

    while (t--) {
        cin >> n;

        vector<int> v;

        for (int i = 1; i < n; i++) {
            int temp = 0; cin >> temp;
            v.push_back(temp);
        }

        int ans = 0;
        
        for (auto it: v) {
            ans += it;
        }

        cout << -1 * ans << endl;
    }

    return 0;
}
