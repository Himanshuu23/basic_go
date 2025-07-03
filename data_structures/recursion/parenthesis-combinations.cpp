/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, string s, vector<string>& ans, int open, int close) {
    if (open == n && close == n) {
        ans.push_back(s);
        return;
    }
    if (open < n) solve(n, s + '(', ans, open + 1, close);
    if (close < open) solve(n, s + ')', ans, open, close + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string>ans;
        solve(n, "", ans, 0, 0);
        for (const string& comb : ans) cout << comb << endl;
    }

    return 0;
}
