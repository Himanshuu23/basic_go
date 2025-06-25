/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void towerOfHanoi(ll n, string source, string destination, string helper) {
    if (n == 1) {
        cout << "Move 1 block from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, helper, destination);
    cout << "Move block " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, helper, destination, source); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        towerOfHanoi(n, "A", "C", "B");
    }

    return 0;
}
