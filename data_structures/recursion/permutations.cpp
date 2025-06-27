/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void permutations(ll i, vector<int> &v) {
    if (i == v.size()) { 
        for (int j = 0; j < v.size(); j++) { 
            cout << v[j] << " "; 
        }
        cout << endl;
        return;
    }
    for (int j = i; j < v.size(); j++) {
        swap(v[j], v[i]);
        permutations(i+1, v);
        swap(v[j], v[i]);
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
        permutations(0, v);
    }

    return 0;
}
