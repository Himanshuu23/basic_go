/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MyCircularDeque {
private:
    vector<int> deque;
    int front, rear, size, capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = -1;
        rear = -1;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            front = (front - 1 + capacity) % capacity;
        }

        deque[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        deque[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + capacity) % capacity;
        }

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }

    int getRear() {
        if (isEmpty()) return -1;
        return deque[rear];
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
        MyCircularDeque dq(3);

        cout << dq.insertLast(1) << endl;
        cout << dq.insertLast(2) << endl;   
        cout << dq.insertFront(3) << endl; 
        cout << dq.insertFront(4) << endl; 
        cout << dq.getRear() << endl;      
        cout << dq.isFull() << endl;       
        cout << dq.deleteLast() << endl;   
        cout << dq.insertFront(4) << endl;
        cout << dq.getFront() << endl;

        return 0;
    }
}
