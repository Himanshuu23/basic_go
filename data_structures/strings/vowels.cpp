/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    int ans(0);
    for (char c : s) if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ans++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
