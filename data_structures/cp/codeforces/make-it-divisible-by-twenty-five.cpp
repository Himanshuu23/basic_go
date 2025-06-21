/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s, string t) {
    int ans(0), l = s.length();
    while(s.length() && t.length()) {
        if (s.back() == t.back()) t.pop_back();
        else ++ans;
        s.pop_back();
    }
    if (t.length() == 0) return ans;
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    cin.ignore();
    while(t--) {
        string s; cin >> s;
        if (s.length() < 2) cout << s.length() << endl;
        else {
            cout << min({ solve(s, "00"), solve(s, "25"), solve(s, "50"), solve(s, "75") }) << endl;
        }
    } 
    return 0;
}
