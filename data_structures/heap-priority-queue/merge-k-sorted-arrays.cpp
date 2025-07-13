/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> Node;

vector<int> solve(const vector<vector<int>>& v, int k) {
    priority_queue<Node, vector<Node>, greater<Node>> mh;
    for (int i = 0; i < k; i++) {
        if (!v[i].empty()) mh.emplace(v[i][0], i, 0);
    }
    vector<int> res;
    while (!mh.empty()) {
        auto [value, r, c] = mh.top();
        mh.pop();
        res.push_back(value);

        if (c + 1 < v[r].size()) mh.emplace(v[r][c+1], r, c + 1);
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        vector<vector<int>> v = {
            {1, 4, 5},
            {1, 3, 4},
            {2, 6},
        };

        vector<int> res = solve(v, 3);
        for (int num : res) cout << num << " ";
        cout << endl;
    }

    return 0;
}
