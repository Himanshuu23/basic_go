/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s) {
    stack<string>st;
    for (auto &ch : s) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            string op1 = st.top(); st.pop();
            string op2 = st.top(); st.pop();
            string expr = ch + op2 + op1;
            st.push(expr);
        } else st.push(string(1, ch));
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
