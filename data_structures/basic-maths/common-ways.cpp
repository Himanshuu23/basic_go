/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        ll n, a, b; cin >> n >> a >> b;
        ll c1 = n / a, c2 = n / b, c3 = n / (a * b);
        cout << "Total numbers between 1 and " << n << " divisible by " << a << " and " << b << " are: " << c1 + c2 - c3 << endl;
    }

    return 0;
}
