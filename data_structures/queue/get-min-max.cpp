/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MinMaxQueue {
    queue<int> q;
    deque<int> minQ, maxQ;
   
public:
    void push (int x) {
        q.push(x);
        while (!minQ.empty() && minQ.back() > x) minQ.pop_back();
        minQ.push_back(x);
        while (!maxQ.empty() && maxQ.back() <= x) maxQ.pop_back();
        maxQ.push_back(x);
    }

    void pop() {
        if (q.front() == minQ.front()) minQ.pop_front();
        else if (q.front() == maxQ.front()) maxQ.pop_front();
        q.pop();
    }
    int getMin() { return minQ.front(); }
    int getMax() { return maxQ.front(); } 
};

int main() {
    MinMaxQueue q;
    q.push(4);
    q.push(1);
    q.push(3);
    cout << "Min: " << q.getMin() << ", Max: " << q.getMax() << endl;

    q.pop();
    cout << "Min: " << q.getMin() << ", Max: " << q.getMax() << endl;

    q.pop(); 
    cout << "Min: " << q.getMin() << ", Max: " << q.getMax() << endl;

    return 0;
}
