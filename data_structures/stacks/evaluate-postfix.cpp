/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    stack<int>st;
    for (auto &ch : s) {
        if (isdigit(ch)) st.push(ch - '0');
        else {
            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int res;
            if (ch == '+') res = op2 + op1;
            else if (ch == '-') res = op2 - op1;
            else if (ch == '*') res = op2 * op1;
            else res = op2 / op1;
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
