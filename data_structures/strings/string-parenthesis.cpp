/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(char t, char c) {
    bool flag = false;
    if (c == '(') flag = t == ')';
    else if (c == '[') flag = t == ']';
    else if (c == '{') flag = t == '}';
    return flag;
}

bool solve(string s) {
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);
        else {
            if (!st.empty() && check(s[i], st.top())) st.pop();
            else return false;
        }
    }

    return st.empty();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        puts(solve(s) ? "True" : "False");
    }

    return 0;
}
