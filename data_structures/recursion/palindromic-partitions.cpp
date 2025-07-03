/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

bool isPalin(const string& s, int l, int r) {
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

void dfs(int start, const string& s, vector<string>& path, vector<vector<string>>& res) {
    if (start == s.size()) {
        res.push_back(path);
        return;
    }
    for (int end = start; end < s.size(); ++end) {
        if (isPalin(s, start, end)) {
            path.push_back(s.substr(start, end - start + 1));
            dfs(end + 1, s, path, res);
            path.pop_back();
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, path, res);
        for (auto& part : res) {
            for (auto& p : part) cout << p << " ";
            cout << endl;
        }
    }
    return 0;
}
