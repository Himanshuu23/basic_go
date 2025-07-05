/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int n, vector<int>& v, int x) {
    int start(0), end(n - 1);
    while (start < end) {
        int mid = (start + end) / 2;
        if (v[mid] == x) return mid;
        else if (mid > 0 && v[mid - 1] == x) return mid - 1;
        else if (mid < n - 1 && v[mid + 1] == x) return mid + 1;

        else if (v[mid] > x) end = mid - 2;
        else start = mid + 2;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, x; cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n, v, x) << endl; 
    }

    return 0;
}
