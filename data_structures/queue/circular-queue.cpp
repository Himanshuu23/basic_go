/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class CircularQueue {
private:
    vector<int> data;
    int front, rear, size, capacity;

public:
    CircularQueue(int k) {
        data.resize(k);
        front = 0;
        rear = -1;
        size = 0;
        capacity = k;
    }

    bool enqueue(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
        return true;
    }

    bool dequeue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[front];
    }

    int Rear() {
        return isEmpty() ? -1 : data[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        CircularQueue cq(3);
        cout << cq.enqueue(1) << endl;
        cout << cq.enqueue(2) << endl;
        cout << cq.enqueue(3) << endl;
        cout << cq.enqueue(4) << endl;

        cout << cq.Rear() << endl;
        cout << cq.isFull() << endl;

        cout << cq.dequeue() << endl;
        cout << cq.enqueue(4) << endl;

        cout << cq.Rear() << endl;  
        cout << cq.Front() << endl;    
    }

    return 0;
}
