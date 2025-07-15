/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const vector<int>& v, int n) {
    unordered_map<int, int> mp;
    int ans(0), start(0), end(0);

    while (end < n) {
        mp[v[end]]++;

        while (mp.size() > 2) {
            mp[v[start]]--;
            if (mp[v[start]] == 0) mp.erase(v[start]);
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
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(v, n) << endl;
    }

    return 0;
}
