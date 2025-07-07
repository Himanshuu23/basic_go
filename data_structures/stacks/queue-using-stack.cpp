/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Queue {
    stack<int> in, out;

    void enqueue(int x) {
        in.push(x);
    }

    int dequeue() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        int res = out.top();
        out.pop();
        return res;
    }

    int front() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }

    bool empty() {
        return in.empty() && out.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Queue q;
        q.enqueue(1);
        q.enqueue(2);
        cout << q.front() << endl;
        q.dequeue();
        q.enqueue(3);
        cout << q.empty() << endl;
        q.enqueue(4);
    }

    return 0;
}
