/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSorted(int n, int a[]) {
    bool flag = true;
    if (n >= 1) return flag;
    flag = a[n - 1] > a[n - 2];
    return flag && isSorted(n - 1, a);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << isSorted(n , a) << endl;
    }

    return 0;
}
