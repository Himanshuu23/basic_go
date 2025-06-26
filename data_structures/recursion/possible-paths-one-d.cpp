/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void printPossible(int start, int end, int &ans) {
    if (start > end) return;
    if (start == end) ++ans;
    for (int i = 1; i <= 6; i++) {
        printPossible(start + i, end, ans);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, ans(0); cin >> n;
        printPossible(0, n, ans);
        cout << ans << endl;
    }

    return 0;
}
