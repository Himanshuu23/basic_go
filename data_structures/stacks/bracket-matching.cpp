/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool shallIPop(char c1, char c2) {
    bool flag = false;
    if (c1 == '(') flag = c2 == ')';
    if (c1 == '[') flag = c2 == ']';
    if (c1 == '{') flag = c2 == '}';
    return flag;
}

bool solve(string s) {
    stack<int> stack;
    for (auto &ch : s) {
        if (ch == '[' || ch == '{' || ch == '(') stack.push(ch);
        else if (!stack.empty() && shallIPop(stack.top(), ch)) stack.pop();
    }

    if (stack.empty()) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        string s; cin >> s;
        if (solve(s)) cout << "Balanced" << endl;
        else cout << "Unbalanced" << endl;
    }

    return 0;
}
