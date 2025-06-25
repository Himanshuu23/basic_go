/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void replace(string s, int n) {
    if (n < 0) return;
    replace(s, n - 1);
    if (n + 1 < s.size() && s[n] == 'p' && s[n+1] == 'i') cout << "3.14";
    else if (n != 0 && s[n] != 'i' && s[n-1] != 'p') cout << s[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        replace(s, s.size() - 1);
    }

    return 0;
}
