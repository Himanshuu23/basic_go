/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, vector<int>& v) {
    int mx = *max_element(v.begin(), v.end());
    vector<int>count(mx + 1, 0);

    for (int num : v) count[num]++;
    int index(0);
    for (int i = 0; i <= mx; i++) {
        while(count[i]--) v[index++] = i;
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
