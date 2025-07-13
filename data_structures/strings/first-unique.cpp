/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char solve(string s) {
    unordered_map<char, int> mp;
    for (char c : s) mp[c]++;
    for (char c : s) if (mp[c] == 1) return c;
    return -1;
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
