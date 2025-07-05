/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int countInRange(vector<int>& v, int n, int left, int right) {
    int ct(0);
    for (int i = left; i <= right; i++) {
        if (v[i] == n) ct++;
    }
    return ct;
}

int usingDivideAndConquer(vector<int>& v, int left, int right) {
    if (left == right) return v[left];
    int mid = (left + right) / 2;
    int leftMajor = usingDivideAndConquer(v, left, mid);
    int rightMajor = usingDivideAndConquer(v, mid + 1, right);

    if (leftMajor == rightMajor) return leftMajor;

    int leftCount = countInRange(v, leftMajor, left, right);
    int rightCount = countInRange(v, rightMajor, left, right);

    return leftCount > rightCount ? leftMajor : rightMajor;
}

int solve(int n, vector<int>& v) {
    int target(n / 2), ans(0), ct(0);
    for (int i = 0; i < n; i++) {
        if (ct == 0) {
            ans = max(ans, v[i]);
            ct++;
        } else if (v[i] == ans) ++ct;
        else --ct;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << solve(n, v) << endl;
        cout << usingDivideAndConquer(v, 0, 0) << endl;
    }

    return 0;
}
