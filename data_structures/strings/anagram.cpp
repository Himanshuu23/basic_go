/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isAnagram(string s, string m) {
    if (s.size() != m.size()) return false;

    bool flag = true;
    unordered_map<char, int> mp;

    for (int i = 0; i < s.size(); i++) {
        mp[s[i]]++;
        mp[m[i]]--;
    }

    for (auto& [key, val] : mp) {
        if (val != 0) flag = false;
    }

    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, m; cin >> s >> m;
        puts(isAnagram(s, m) ? "Yes" : "No");
    }

    return 0;
}
