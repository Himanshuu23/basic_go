/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sum(int n) {
    if (n == 0) return 0;
    int prev = sum(n - 1);
    return n + prev;
}

int power(int n, int p) {
    if (p == 0) return 1;
    int prev = power(n, p - 1);
    return n * prev;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, p; cin >> n >> p;
        cout << sum(n) << endl;
        cout << power(n, p) << endl;
    }

    return 0;
}
