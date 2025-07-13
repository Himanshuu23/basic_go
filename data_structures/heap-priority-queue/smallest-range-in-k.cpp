/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> Node;

pair<int, int> solve(vector<vector<int>>& v, int k) {
    priority_queue<Node, vector<Node>, greater<>> mh;
    int mx = INT_MIN;

    for (int i = 0; i < k; i++) {
        if (!v[i].empty()) { 
            mh.emplace(v[i][0], i, 0);
            mx = max(v[i][0], mx);
        }
    }

    int rangeStart(0), rangeEnd(INT_MAX);

    while (!mh.empty()) {
        auto [val, r, c] = mh.top();
        mh.pop();

        if (mx - val < rangeEnd - rangeStart) {
            rangeStart = val;
            rangeEnd = mx;
        }

        if (c + 1 < v[r].size()) {
            int nextVal = v[r][c+1];
            mh.emplace(nextVal, r, c + 1);
            mx = max(mx, nextVal);
        } else break;
    }

    return {rangeStart, rangeEnd};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        vector<vector<int>> lists = {
            {4, 10, 15, 24, 26},
            {0, 9, 12, 20},
            {5, 18, 22, 30}
        };
    
        pair<int, int> result = solve(lists, lists.size());
        cout << "Smallest Range: [" << result.first << ", " << result.second << "]" << endl;
    }

    return 0;
}
