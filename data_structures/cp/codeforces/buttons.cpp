/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long a = 0, b = 0, c = 0;
        
        cin >> a >> b >> c;

        if (a == b)
            (c % 2 == 0) ? cout << "Second" << endl : cout << "First" << endl;

        else
            (a > b) ? cout << "First" << endl : cout << "Second" << endl;
    }

    return 0;
}
