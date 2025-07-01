/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int minMaxTarget(int n, vector<int> &v, int target) {
    sort(v.begin(), v.end());
    vector<int>power(n+1, 1);
    for (int i = 1; i <= n; i++) power[i] = (power[i-1]*2)%MOD;
    int ans(0), left(0), right(n-1);
    for (int i = 0; i < n; i++) {
        if (v[left] + v[right] <= target) {
            ans = (ans + power[right - left]) % MOD;
            ++left;
        } else --right;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, target; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cin >> target;
        cout << minMaxTarget(n, v, target) << endl;
    }

    return 0;
}
