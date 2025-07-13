/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Stream{
    priority_queue<int> mxh;
    priority_queue<int, vector<int>, greater<int>> mnh;

public:
    void addNum(int value) {
        if (mxh.empty() || value <= mxh.top()) mxh.push(value);
        else mnh.push(value);

        if (mxh.size() > mnh.size() + 1) {
            mnh.push(mxh.top());
            mxh.pop();
        } else if (mnh.size() > mxh.size() + 1) {
            mxh.push(mnh.top());
            mnh.pop();
        }
    }

    double getMedian() {
        int mx = mxh.size(), mn = mnh.size();
        return ((mx + mn) % 2 == 0) ? (mxh.top() + mnh.top()) / 2.0 : (mx > mn ) ? mnh.top() : mxh.top();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Stream s;
        s.addNum(5);
        s.addNum(2);
        s.addNum(10);
        s.addNum(1);
        cout << s.getMedian() << endl;
    }

    return 0;
}
