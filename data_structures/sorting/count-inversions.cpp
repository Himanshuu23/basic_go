/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, vector<int>& v, int &ct, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    solve(n, v, ct, left, mid);
    solve(n, v, ct, mid + 1, right);

    vector<int> temp;
    int i = left, j = mid + 1;
    while (i <= mid && j <= right) {
        if (v[i] > v[j]) { 
            temp.push_back(v[j++]);
            ct += (mid - i + 1);
        } else temp.push_back(v[i++]);
    }

    while (i <= mid) temp.push_back(v[i++]);
    while (j <= right) temp.push_back(v[j++]);

    for (int k = 0; k < temp.size(); ++k) v[left + k] =  temp[k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, ct(0); cin >> n;
        vector<int>v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        solve(n, v, ct, 0, n - 1);
        cout << ct << endl;
    }

    return 0;
}
