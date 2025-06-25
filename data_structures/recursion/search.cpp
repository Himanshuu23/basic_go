/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void firstLastOcc(ll n, int a[], int i, int key, int &first, int &last) {
    if (i == n) {
        return;
    }

    if (a[i] == key) {
        if (first == -1) first = i;
        else if (last == -1 && i >= first) last = i;
    }

    firstLastOcc(n, a, i + 1, key, first, last);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        int key, first = -1, last = -1; cin >> key;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        firstLastOcc(n, a, 0, key, first, last);
        cout << first << " " << last << endl;
    }

    return 0;
}
