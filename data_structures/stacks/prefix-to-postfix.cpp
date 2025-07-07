/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    stack<string>st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = op1 + op2 + s[i];
            st.push(expr);
        } else st.push(string(1, s[i]));
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
