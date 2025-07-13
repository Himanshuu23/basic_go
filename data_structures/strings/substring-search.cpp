/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s, string substr) {
    int n(s.size()), m(substr.size());

    for (int i = 0; i <= n - m; i++) {
        int j(0);
        while (j < m && s[i+j] == substr[j]) {
            j++;
        }
        if (j == m) return i;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, substr; cin >> s >> substr;
        cout << solve(s, substr) << endl;
    }

    return 0;
}
