#include <bits/stdc++.h>
using namespace std;

int firstRepeatingElement(vector<int>& array, int n) {
    vector<int> idx(n, -1);
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (idx[array[i]] != -1) {
            ans = min(ans, idx[array[i]]);
        }

        idx[array[i]] = i;
    }

    if (ans == INT_MAX) {
        return -1;
    } else {
        return ans;
    }
}

int main() {
    vector<int> v = { 1, 5, 3, 4, 3, 5, 6 };
    cout << firstRepeatingElement(v, v.size()) << endl;
    return 0;
}
