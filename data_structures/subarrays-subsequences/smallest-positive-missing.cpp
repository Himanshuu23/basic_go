#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 2;

int smallestPositiveMissing(vector<int>& array, int n) {
    vector<bool> check(N, 0);

    for (int i = 0; i < n; i++) {
        if (array[i] >= 0) {
            check[array[i]] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (!check[i]) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n; cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        v.push_back(temp);
    }

    cout << smallestPositiveMissing(v, n) << endl;
}
