/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void substring(string s, int i) {
    if (i < 0) return;
    substring(s, i-1);
    cout << s.substr(0, i) << endl;
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
