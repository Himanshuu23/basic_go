/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class MinHeap{
    vector<int> heap;

    void heapify_up(int i) {
        int p = (i - 1) / 2;
        while (i > 0 && heap[p] > heap[i]) {
            swap(heap[i], heap[p]);
            i = p;
        }
    }

    void heapify_down(int i) {
        int n = heap.size();
        while (2 * i + 1 < n) {
            int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (i != smallest) {
                swap(heap[i], heap[smallest]);
                i = smallest;
            } else break;
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    void remove_top() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
    }

    int top() {
        return (heap.empty()) ? -1 : heap[0];
    }

    int size() {
        return heap.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int> res, v(n);
        MinHeap mh;
        for (int i = 0; i < n; i++) cin >> v[i];
        for (int i = 0; i <= k && i < n; i++) mh.insert(v[i]);
        for (int i = k + 1; i < n; i++) {
            res.push_back(mh.top());
            mh.remove_top();
            mh.insert(v[i]);
        }
        while (mh.size() > 0) {
            res.push_back(mh.top());
            mh.remove_top();
        }
        for (int num : res) cout << num << " ";
        cout << endl;
    }

    return 0;
}
