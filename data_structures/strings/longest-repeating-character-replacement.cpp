/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(const string& s, int k) {
    vector<int> count(26, 0);
    int mxCt(0), start(0), ans(0);    

    for (int end = 0; end < s.size(); end++) {
        count[s[end] - 'A']++;
        mxCt = max(mxCt, count[s[end] - 'A']); // counting the most frequenct char

        while ((end - start + 1) - mxCt > k) { // if more than k replacement needed then shrink the window
            count[s[start] - 'A']--;
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
