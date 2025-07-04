/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int partition(vector<int>& v, int left, int right) {
    int pivot = v[right];
    int p = left;
    for (int i = left; i < right; ++i) {
        if (v[i] > pivot) {
            swap(v[i], v[p]);
            ++p;
        }
    }
    swap(v[p], v[right]);
    return p;
}

int solveUsingQuickSelect(int n, vector<int>& v, int k) {
    int left = 0, right = n - 1;
    k -= 1;
    while (left <= right) {
        int pos = partition(v, left, right);
        if (pos == k) return v[pos];
        else if (pos < k) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

int solveUsingPriorityQueue(int n, vector<int>& v, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : v) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solveUsingQuickSelect(n, v, k) << endl;
        cout << solveUsingPriorityQueue(n, v, k) << endl;
    }

    return 0;
}
