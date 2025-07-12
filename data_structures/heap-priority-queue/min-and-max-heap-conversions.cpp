/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MinMaxHeap {
    vector<int> heap;
    bool isMinHeap;

    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b;  
    }

    void heapify_up(int i) {
        int p = (i - 1) / 2;
        while (i > 0) {
            if (i > 0 && compare(heap[i], heap[p])) {
                swap(heap[i], heap[p]);
                i = p;
            } else break;
        }
    }

    void heapify_down(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int l = 2 * i + 1, r = 2 * i + 2, comparator = i;
            if (l < n && compare(heap[l], heap[comparator])) comparator = l;
            if (r < n && compare(heap[r], heap[comparator])) comparator = r;
            if (i != comparator) {
                swap(heap[i], heap[comparator]);
                i = comparator;
            } else break;
        }
    }

public:
    MinMaxHeap(bool isMin) {
        this->isMinHeap = isMin;
    }

    void insert(int val) {
        heap.push_back(val);
        heapify_up(heap.size() - 1);
    }

    void remove_top() {
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    int top() {
        return heap.empty() ? -1 : heap[0];
    }

    int size() {
        return heap.size();
    }

    vector<int> getHeap() {
        return heap;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        bool isMin; cin >> isMin;
        MinMaxHeap heap(isMin);
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            heap.insert(temp);
        }
        vector<int> ans = heap.getHeap();
        for (int num : ans) cout << num << " ";
        cout << endl;
    }

    return 0;
}
