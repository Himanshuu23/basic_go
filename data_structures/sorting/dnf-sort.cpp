/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, vector<int>& v) {
    int low(0), mid(0), high(n - 1);
    while (mid <= high) {
        if (v[mid] == 0) swap(v[mid++], v[low++]);
        else if (v[mid] == 1) mid++;
        else swap(v[mid], v[high--]);
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
