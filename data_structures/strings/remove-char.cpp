/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, char ch) {
    string ans;
    for (char c : s) if (c != ch) ans += c;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        char ch; cin >> ch;
        cout << solve(s, ch) << endl;
    }

    return 0;
}
