/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(string s, string t) {
    vector<int>ans;
    int sLen(s.length()), tLen(t.length());
    if (sLen < tLen) return ans;
    vector<int> tCount(26, 0), windowCount(26, 0);
    for (char c : t) tCount[c - 'a']++;

    for (int i = 0; i < sLen; i++) {
        windowCount[s[i] - 'a']++;
        if (i >= tLen) windowCount[s[i - tLen] - 'a']--;
        if (windowCount == tCount) ans.push_back(i - tLen + 1);
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        vector<int>ans = solve(s, t);
        for (auto num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
