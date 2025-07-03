/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void substring(string s, int i) {
    if (i < 0) return;
    substring(s, i-1);
    cout << s[i] << endl;
    for (int j = 0; j < i; j++) {
        cout << s.substr(j, i - j + 1) << endl;
    }
}

void solve(string s, int start, int end) {
    if (start == s.size()) return;
    if (end == s.size() + 1) solve(s, start + 1, start + 1);
    else {
        cout << s.substr(start, end - start) << endl;
        solve(s, start, end + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
         substring(s, s.size());
        solve(s, 0, 1);
    }

    return 0;
}
