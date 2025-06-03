#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr;

    if (n == 1) {
        return 1;
    }

    if (n == 2) {
        return 2;
    }

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        arr.push_back(temp);
    }

    int pd = arr[1] - arr[0], ans = 2, curr = 2;

    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i-1] == pd) {
            curr++;
        } else {
            pd = arr[i] - arr[i-1];
            curr = 2;
        }

        ans = max(ans, curr);
    }

    cout << ans << endl;
    return 0;
}
