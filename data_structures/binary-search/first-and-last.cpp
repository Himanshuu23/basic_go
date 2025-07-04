/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;

pair<int, int> findFirstAndLast(vector<int>& v, int target) {
    int n = v.size();
    int first = -1, last = -1;

    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == target) {
            first = mid;
            high = mid - 1;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (v[mid] == target) {
            last = mid;
            low = mid + 1;
        } else if (v[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return {first, last};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n, target; cin >> n >> target;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        auto [first, last] = findFirstAndLast(v, target);
        cout << first << " " << last << "\n";
    }

    return 0;
}
