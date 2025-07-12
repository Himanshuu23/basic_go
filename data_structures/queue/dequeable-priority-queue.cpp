/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Depq {
    vector<int> heap;
    unordered_map<int, set<int>> idx_map;

    void swap_nodes(int i, int j) {
        swap(heap[i], heap[j]);
        idx_map[heap[i]].insert(i);
        idx_map[heap[i]].erase(j);
        idx_map[heap[j]].insert(j);
        idx_map[heap[j]].erase(j);
    }

    void heapify_up(int i) {
        int p = (i - 1) / 2;
        while (i > 0) {
            if (heap[i] > heap[p]) {
                swap_nodes(i, p);
                i = p;
            } else break;
        }
    }

    void heapify_down(int i) {
        int n = heap.size();
        while (2 * i + 1) {
            int left = 2 * i + 1, right = 2 * i + 2, largest = i;
            if (left < n && heap[left] > heap[largest]) largest = left;
            if (right < n && heap[right] > heap[largest]) largest = right;
            if (largest != i) {
                swap_nodes(i, largest);
                i = largest;
            } else break;
        }
    }

public: 
    void insert(int value) {
        heap.push_back(value);
        idx_map[value].insert(heap.size() - 1);
        heapify_up(heap.size() - 1);
    }

    void remove(int value) {
        if (idx_map.find(value) == idx_map.end() || idx_map[value].empty()) return;

        int i = *idx_map[value].begin();
        idx_map[value].erase(i);

        int last = heap.back();
        heap.pop_back();
        if (i == heap.size()) return;

        heap[i] = last;
        idx_map[last].erase(heap.size());
        idx_map[last].insert(i);

        heapify_up(i);
        heapify_down(i);
    }

    int get_top() {
        return heap.empty() ? -1 : heap[0];
    }

    bool contains(int value) {
        return idx_map.count(value) && !idx_map[value].empty(); 
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
        Depq pq;
        pq.insert(10);
        pq.insert(20);
        pq.insert(10);

        pq.remove(10);
        pq.remove(10);

        if (pq.contains(10)) cout << "Test failed: 10 is still in the map.\n";
        else cout << "Test passed: 10 was successfully removed from the map\n";
    }

    return 0;
}
