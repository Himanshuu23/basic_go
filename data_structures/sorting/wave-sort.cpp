/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, vector<int>& v) {
    for (int i = 0; i < n; i += 2) {
        if (i > 0 && v[i - 1] > v[i]) swap(v[i - 1], v[i]);
        else if (i < n - 1 && v[i + 1] > v[i]) swap(v[i + 1], v[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        solve(n, v);
        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }

    return 0;
}
