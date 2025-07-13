/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Stream {
    priority_queue<int> pq;
    int k;
public:
    Stream(int val) : k(val) {}

    void insert(int val) {
        if (pq.size() < k) {
            pq.push(val);
        } else if (val < pq.top()) {
            pq.pop();
            pq.push(val);
        }
    }

    int who() { 
        return (pq.size() < k) ? -1 : pq.top(); 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Stream s(3);
        s.insert(5);
        cout << s.who() << endl;
        s.insert(1);
        cout << s.who() << endl;
        s.insert(3);
        cout << s.who() << endl;
        s.insert(2);
        cout << s.who() << endl;
        s.insert(4);
        cout << s.who() << endl;
        s.insert(6);
        cout << s.who() << endl;
    }

    return 0;
}
