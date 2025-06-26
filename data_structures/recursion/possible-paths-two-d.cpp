/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void findPath(int start1, int start2, int end1, int end2, int &ans, string path) {
    if (start1 == end1 - 1 && start2 == end2 - 1) {
        cout << path << endl;
        ++ans;
    }
    if (start1 >= end1 || start2 >= end2) return;
    findPath(start1 + 1, start2, end1, end2, ans, path + "R");
    findPath(start1, start2 + 1, end1, end2, ans, path + "D");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int m, n, i, j, ans(0); cin >> m >> n >> i >> j;
        string path;
        findPath(m, n, i, j, ans, path);
        cout << "Total possible ways are " << ans << endl;
    }

    return 0;
}
