#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n) {
    return n && !(n & (n - 1));
}

int main() {
    int n; cin >> n;

    if (isPowerOfTwo(n)) {
        cout << "True" << endl;
    } else { 
        cout << "False" << endl;
    }

    return 0;
}
