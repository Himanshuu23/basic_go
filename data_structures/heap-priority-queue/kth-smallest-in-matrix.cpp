/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<vector<int>>& m, int n, int k) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> mh;
    for (int i = 0; i < n; i++) mh.emplace(m[i][0], i, 0);
    int res(-1);
    while (!mh.empty() && k--) {
        auto [val, r, c] = mh.top();
        mh.pop();
        res = val;

        if (c + 1 < n) mh.emplace(m[r][c + 1], r, c + 1);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        cout << solve(v, n, k) << endl;
    }

    return 0;
}
