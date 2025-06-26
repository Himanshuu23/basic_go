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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        substring(s, s.size());
    }

    return 0;
}
