/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void permutations(int i, vector<int> &v) {
    if (i == v.size()) {
        for (int j = 0; j < v.size(); j++) {
            cout << v[j] << " ";
        }
        cout << endl;
        return;
    }

    unordered_set<int> used;
    for (int j = i; j < v.size(); j++) {
        if (used.count(v[j])) continue;
        used.insert(v[j]);

        swap(v[i], v[j]);
        permutations(i+1, v);
        swap(v[i], v[j]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        permutations(0, v);
    }

    return 0;
}
