/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve (vector<int>& v, int left, int right) {
    if (left >= right) return;
    int pivot = v[right];
    int i = left;
    for (int j = left; j < right; j++) {
        if (v[j] < pivot) { 
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[right]);
    solve(v, left, i - 1);
    solve(v, i + 1, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        solve(v, 0, n);
        for (int i = 0; i < n; i++) cout << v[i] << " " << endl;
    }

    return 0;
}
