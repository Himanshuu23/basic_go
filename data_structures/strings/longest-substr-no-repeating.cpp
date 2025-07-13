/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    unordered_map<char, int> seen;
    int left(0), maxLen(0), start(0);

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        if (seen.count(c) && seen[c] >= left) left = seen[c] + 1;
        seen[c] = right;
        if (right - left + 1> maxLen) {
            maxLen = right - left + 1;
            start = left;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
