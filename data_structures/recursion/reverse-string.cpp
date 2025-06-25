/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string reverse(string s, int i) {
    if (i < 0) return "";
    return s[i] + reverse(s, i - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << reverse(s, s.size() - 1) << endl;
    }

    return 0;
}
