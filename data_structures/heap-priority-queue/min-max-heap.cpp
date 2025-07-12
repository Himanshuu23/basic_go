/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MaxHeap {
    vector<int> heap;

    void heapify_up(int i) {
        int p = (i - 1) / 2;
        while (i > 0 && heap[i] > heap[p]) {
            swap(heap[i], heap[p]);
            i = p;
        }
    }

    void heapify_down(int i) {
        int n = heap.size();
        while (2 * i + 1) {
            int left = 2 * i + 1, right = 2 * i + 2, largest = i;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (i != largest) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public: 
    void insert(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    int get_top() {
        return heap.empty() ? -1 : heap[0];
    }

    void remove_top() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {

    }

    return 0;
}
