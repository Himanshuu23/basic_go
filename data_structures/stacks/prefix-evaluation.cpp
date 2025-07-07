/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    stack<int>st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isdigit(s[i])) st.push(s[i] - '0');
        else {
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int res;
            if (s[i] == '+') res = op1 + op2;
            else if (s[i] == '-') res = op1 - op2;
            else if (s[i] == '*') res = op1 * op2;
            else res = op1 / op2;
            st.push(res);
        }
    }

    return st.top();
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
