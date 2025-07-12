/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n) {
    queue<string> q;
    q.push("1");
    while (n--) {
        string top = q.front(); q.pop();
        cout << top << "\n";
        q.push(top + "0");
        q.push(top + "1");
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n; cin >> n;
        solve(n);
    }

    return 0;
}
