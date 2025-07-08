/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(stack<int>& st) {
    stack<int> s;
    while (!st.empty()) {
        int temp = st.top(); st.pop();
        while (!s.empty() && s.top() >= temp) {
            st.push(s.top()); s.pop();
        }
        s.push(temp);
    }
    while (!s.empty()) {
        st.push(s.top());
        s.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        stack<int> st;
        st.push(2);
        st.push(1);
        st.push(3);
        solve(st);
        cout << st.top() << endl; st.pop();
        cout << st.top() << endl; st.pop();
        cout << st.top() << endl; st.pop();
    }

    return 0;
}
