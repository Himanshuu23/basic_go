/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    stack<int> st; st.push(-1);
    int ans(0), curr(0);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') st.push(i);
        else {
            st.pop();
            if (!st.empty()) ans = max(ans, i - st.top());
            else st.push(i);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
