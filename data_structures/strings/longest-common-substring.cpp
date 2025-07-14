/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const string& s, const string& k) {
    int n = s.length(), m = k.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int mx = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == k[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                mx = max(mx, dp[i][j]);
            }
        }
    }

    return mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s, k; cin >> s >> k;
        cout << solve(s, k) << endl;
    }

    return 0;
}
