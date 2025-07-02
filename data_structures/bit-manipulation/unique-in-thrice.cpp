/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> &v) {
    int ones(0), twos(0);
    for (auto num : v) {
        ones = (ones ^ num) & ~(twos);
        twos = (twos ^ num) & ~(ones);
    }
    return ones;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n, v) << endl;
    }

    return 0;
}
