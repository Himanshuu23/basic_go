/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s, int k) {
    string ans; int ct(0);
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '-') continue;
        ans += toupper(s[i]);
        ct++;
        if (ct == k) {
            ct = 0;
            ans += '-';
        }
    }
    if (!ans.empty() && ans.back() == '-') ans.pop_back();
    reverse(ans.begin(), ans.end());
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; int k;
        cin >> s >> k;
        cout << solve(s, k) << endl;
    }

    return 0;
}
