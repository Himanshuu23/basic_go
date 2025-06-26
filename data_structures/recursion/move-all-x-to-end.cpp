/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string move(string s, int i) {
    if (i == s.length()) return s;
    if (s[i] == 'x') {
        s.erase(i, 1);
        s += 'x';
        return move(s, i + 1);
    }
    else return move(s, i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << move(s, 0) << endl;
    }

    return 0;
}
