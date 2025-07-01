/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxScore(int n, vector<int> &v, int k) {
    int left(k), right(k), ans(v[k]), mn(v[k]);
    while (left > 0 || right < n - 1) {
        if (left > 0 && (right == n - 1 || v[left-1] >= v[right+1])) {
            --left;
            mn = min(mn, v[left]);
        } else {
            ++right;
            mn = min(mn, v[right]);
        }
        ans = max(ans, mn * (right - left + 1));
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
        cout << maxScore(n, v, k) << endl;
    }

    return 0;
}
