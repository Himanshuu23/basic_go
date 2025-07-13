/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;
    int have(0), needCount(need.size()), left(0), minLen(INT_MAX), minStart(0);
    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        window[c]++;

        if (need.count(c) && window[c] == need[c]) have++;
        while (have == needCount) {
            if ((right - left + 1) < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char toRemove = s[left];
            window[toRemove]--;

            if (need.count(toRemove) && window[toRemove] < need[toRemove]) have--;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
        cout << solve(s, t) << endl;
    }

    return 0;
}
