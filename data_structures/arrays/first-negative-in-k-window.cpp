/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(const vector<int>& v, int n, int k) {
    queue<int> q;
    vector<int> ans;
    int start(0), end(0);

    while (end < n) {
        if (v[end] < 0) q.push(v[end]);
        if (end - start + 1 < k) end++;
        else if (end - start + 1 == k) {
            if (!q.empty()) ans.push_back(q.front());
            else ans.push_back(0);
            if (!q.empty() && v[start] == q.front()) q.pop();
            end++; start++;
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        vector<int>ans = solve(v, n, k);
        for (auto num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
