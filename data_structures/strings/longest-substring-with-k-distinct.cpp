/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const string& s, int k) {
    unordered_map<char, int> mp;
    int start(0), end(0), ans(0);

    for (int end = 0; end < s.size(); end++) {
        mp[s[end]]++;
        while (mp.size() > k) {
            mp[s[start]]--;
            if (mp[s[start]] == 0) mp.erase(s[start]);
            start++;
        }

        ans = max(ans, end - start + 1);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int k; cin >> k;
        cout << solve(s, k) << endl;
    }

    return 0;
}
