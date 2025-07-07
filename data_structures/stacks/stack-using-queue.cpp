/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Stack {
    queue<int> q1, q2;

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Stack st;
        st.push(1);
        st.push(2);
        cout << st.top() << endl;
        st.pop();
        cout << st.top() << endl;
        cout << st.empty() << endl;
    }

    return 0;
}
