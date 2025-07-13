/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> v;
        for (int i = 0; i < n; i++) { int temp; cin >> temp; v.push_back(temp); }
        for (int i = 0; i < m; i++) { int temp; cin >> temp; v.push_back(temp); }
        make_heap(v.begin(), v.end());
        while (!v.empty()) {
            pop_heap(v.begin(), v.end());
            cout << v.back() << " ";
            v.pop_back();
        }
        cout << endl;
    }

    return 0;
}
