/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n), ans;
        priority_queue<pair<int, int>> mh;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i < n; i++) {
            mh.push({v[i], i});
            while (!mh.empty() && mh.top().second <= i - k) mh.pop();
            if (i >= k - 1) ans.push_back(mh.top().first);
        }
        for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
