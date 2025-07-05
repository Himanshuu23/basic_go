/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countLessThanEqualToMid(int n, vector<vector<int>>& v, int mid) {
    int ct(0), row(n - 1), col(0);
    while (row >= 0 && col < n) {
        if (v[row][col] <= mid) {
            ct += row + 1;
            col += 1;
        } else row -= 1;
    }
    return ct;
}

int solve(int n, int k, vector<vector<int>>& v) {
    int low = v[0][0], high = v[n-1][n-1];
    while (low < high) {
        int mid = (low + high) / 2;
        if (countLessThanEqualToMid(n, v, mid) < k) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int>>v(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> v[i][j];
        cout << solve(n, k, v) << endl;
    }

    return 0;
}
