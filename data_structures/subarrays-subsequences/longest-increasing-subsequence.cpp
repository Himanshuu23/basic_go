/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int> &v) {
    vector<int>sub;
    for (int num : v) {
        auto it = lower_bound(sub.begin(), sub.end(), num);
        if (it == sub.end()) sub.push_back(num);
        else *it = num;
    }
    return sub.size();
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
