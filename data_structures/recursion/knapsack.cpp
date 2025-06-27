/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(int i, ll W, vector<int> &wt, vector<int> &val) {
    if (i == wt.size()) return 0;
    int exclude = solve(i + 1, W, wt, val);
    int include = 0;
    if (wt[i] <= W) include = val[i] + solve(i + 1, W - wt[i], wt, val);
    return max(include, exclude);
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n, W; cin >> n >> W;
        vector<int> wt(n), val(n);
        for (int i = 0; i < n; i++) cin >> wt[i];
        for (int i = 0; i < n; i++) cin >> val[i];
        cout << solve(0, W, wt, val) << endl;
    }

    return 0;
}
