/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < n; i++) {
            int p1, p2;
            cin >> p1; cin >> p2;
            v.emplace_back((p1 * p1) + (p2 * p2), p1, p2);
        }
        make_heap(v.begin(), v.end(), greater<>());
        while (k--) {
            pop_heap(v.begin(), v.end(), greater<>());
            auto [dist, x, y] = v.back();
            cout << "(" << x << ", " << y << ") ";
            v.pop_back();
        }
        cout << endl;
    }

    return 0;
}
