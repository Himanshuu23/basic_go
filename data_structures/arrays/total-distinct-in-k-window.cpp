/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(const vector<int>& v, int n, int k) {
    vector<int> ans;
    unordered_map<int, int>mp;
    int curr(0), start(0), end(0);

    while (end < n) {
        mp[v[end]]++;
        if (end - start + 1 == k) { 
            ans.push_back(mp.size());
            mp[v[start]]--;
            if (mp[v[start]] == 0) mp.erase(v[start]);
            start++;
        }
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
        vector<int> ans = solve(v, n, k);
        for (auto num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
