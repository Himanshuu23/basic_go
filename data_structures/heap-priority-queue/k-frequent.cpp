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
        unordered_map<int, int> mp;
        vector<tuple<int, int>> v;
        for (int i = 0; i < n; i++) {
            int temp; cin >> temp;
            mp[temp]++;
        }
        for (const auto& [key, value] : mp) { v.emplace_back(value, key); }
        make_heap(v.begin(), v.end());
        while (k--) {
            pop_heap(v.begin(), v.end());
            auto [ct, el] = v.back();
            cout << el << " ";
            v.pop_back();
        }
        cout << endl;
    }

    return 0;
}
