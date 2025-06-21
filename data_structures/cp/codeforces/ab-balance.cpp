/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        if (s[0] != s.back()) s[0] = s.back();
        cout << s << "\n";
    }

    return 0;
}
