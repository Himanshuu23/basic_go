/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(queue<int>& q) {
    stack<int> help;
    while (!q.empty()) {
        help.push(q.front());
        q.pop();
    }
    while (!help.empty()) {
        q.push(help.top());
        help.pop();
    }
}

void another(queue<int>& q) {
    if (q.empty()) return;
    int front = q.front(); q.pop();
    another(q);
    q.push(front);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        queue<int>q;
        q.push(1);
        q.push(2);
        q.push(3);

        cout << q.front() << endl; q.pop();
        cout << q.front() << endl; q.pop();
        cout << q.front() << endl; q.pop();
        
        q.push(1);
        q.push(2);
        q.push(3);

        solve(q);
        
        cout << q.front() << endl; q.pop();
        cout << q.front() << endl; q.pop();
        cout << q.front() << endl; q.pop();
    }

    return 0;
}
