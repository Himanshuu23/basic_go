/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(const string& text, const string& pattern) {
    int n(text.length()), m(pattern.length());
    vector<int> result;
    if (m > n) return result;

    unordered_map<char, int> shiftTable;
    for (int i = 0; i < m; i++) shiftTable[pattern[i]] = m - i - 1;
    int i(0);

    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[i+j]) j--;
        if (j < 0) {
            result.push_back(i);
            i++;
        } else {
            char mismatchedChar = text[i+m-1];
            int shift = shiftTable.count(mismatchedChar) ? shiftTable[mismatchedChar] : m;
            i += shift;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        vector<int> ans = solve(s, t);
        for (auto num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
