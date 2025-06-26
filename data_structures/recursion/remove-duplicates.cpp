/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string removeDup(string s, int i) {
    if (i == s.length()) return s;
    if (count(s.begin(), s.end(), s[i]) > 1) {
        s.erase(i, 1);
        return removeDup(s, i);
    }
    else return removeDup(s, i+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << removeDup(s, 0) << endl;
    }

    return 0;
}
