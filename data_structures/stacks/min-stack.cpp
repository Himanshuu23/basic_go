/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Stack{
    stack<int> st, minSt;

    void push (int x) { 
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) minSt.push(x);
    }
    void pop () { 
        if (st.top() == minSt.top()) minSt.pop();
        st.pop(); 
    }
    int top (int x) { return st.top(); }
    int getMin () { return minSt.top(); }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Stack st;
        st.push(1);
        st.push(2);
        st.push(0);
        st.push(5);
        cout << st.getMin() << endl;
    }

    return 0;
}
