/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    if (s.empty()) return "";

    int start(0), maxLen(1);
    for (int center = 0; center < s.size(); center++) {
        int left = center, right = center;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--; right++;
        }

        left = center; right = center + 1;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--; right++;
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
