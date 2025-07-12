/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MaxHeap{
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
            int l = 2 * i + 1, r = 2 * i + 2, largest = i;
            if (l < n && heap[l] > heap[largest]) largest = l;
            if (r < n && heap[r] > heap[largest]) largest = r;
            if (i != largest) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapify_up(heap.size() - 1);
    }

    void remove() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    int top() {
        if (heap.empty()) return -1;
        int res = heap[0];
        remove();
        return res;
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
        int n; cin >> n;
        MaxHeap mh;
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            mh.insert(temp);
        }

        while (!mh.empty()) {
            cout << mh.top() << " ";
        }
        cout << endl;
    }

    return 0;
}
