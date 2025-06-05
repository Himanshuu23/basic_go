#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (((i + j) % 4 == 0) || (i == 2 && j % 4 == 0)) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
