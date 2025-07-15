/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const vector<int>& v, int n, int k) {
    int sum(0), ans(0), end(0), start(0);
    
    while (end < n) {
        sum += v[end];
        while (sum > k) {
            sum -= v[start];
            start++;
        }
        ans = max(ans, end - start + 1);
        end++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(v, n, k) << endl;
    }

    return 0;
}
