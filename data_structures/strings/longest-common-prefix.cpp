/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(vector<string>& v, int n) {
    string ans, prefix(v[0]); int mx(0);
    for (int col = 0; col < v[0].size(); col++) {
        char currentChar = v[0][col];
        for (int row = 1; row < n; row++) {
            if (col >= v[row].size() || v[row][col] != currentChar) return v[0].substr(0, col);
        }
    }
    return v[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(v, n) << endl;
    }

    return 0;
}
