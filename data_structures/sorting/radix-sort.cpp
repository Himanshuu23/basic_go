/*
    author: Himanshuu23
    
    Radix Sort for bounded range
    Why is it efficient for bounded-range?
    Fewer digits to process (e.g., 4-digit numbers need only 4 passes).
    Each pass (Counting Sort) is O(n + k) where k = 10 (for digits 0–9).
    So overall time becomes O(d * (n + k)), where:
        d is number of digits in the largest number (small for bounded data).
        n is number of elements.
        k is constant (like 10 for decimal digits).

    If your data is like:
    [532, 124, 311, 100, 421]
    All values are:
        Non-negative integers
        Within a small range (0 to 999)
➡️   Perfect case for Radix Sort. It sorts fast in 3 digit-level passes.
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void countingSort(int n, vector<int>& v, int exp) {
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(v[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i++) {
        int idx = (v[i] / exp) % 10;
        output[count[idx] - 1] = v[i];
        count[idx]--;
    }
    for (int i = 0; i < n; i++) v[i] = output[i];
}

void solve(int n, vector<int>& v) {
    int mx = *max_element(v.begin(), v.end());
    for (int exp = 1; mx / exp > 0; exp *= 10) countingSort(n, v, exp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        solve(n, v);
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}
