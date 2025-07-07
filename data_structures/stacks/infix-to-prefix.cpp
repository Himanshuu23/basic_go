/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string solve(string s) {
    stack<char> st;
    string prefix;

    reverse(s.begin(), s.end());
    for (char &ch : s) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    for (char &ch : s) {
        if (isalnum(ch)) {
            prefix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop(); 
        }
        else { 
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                prefix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        cout << solve(s) << endl;
    }

    return 0;
}
