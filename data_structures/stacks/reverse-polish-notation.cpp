/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<string>& v, int n) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
        string token = v[i];

        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (st.size() < 2) throw runtime_error("Invalid expression");

            int op1 = st.top(); st.pop();
            int op2 = st.top(); st.pop();
            int result;

            if (token == "+") result = op2 + op1;
            else if (token == "-") result = op2 - op1;
            else if (token == "*") result = op2 * op1;
            else result = op2 / op1;

            st.push(result);
        } else {
            st.push(stoi(token));
        }
    }

    if (st.size() != 1) throw runtime_error("Invalid RPN expression");
    return st.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<string>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(v, n) << endl;
    }

    return 0;
}
