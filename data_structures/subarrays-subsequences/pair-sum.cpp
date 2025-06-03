#include <bits/stdc++.h>
using namespace std;

bool pairExists(vector<int>& arr, int n, int sum) {
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (mp.count(sum - arr[i])) {
            cout << i << " " << mp[sum - arr[i]] << endl;
            return true;
        } else {
            mp[arr[i]] = i;
        }
    }
    
    cout << "No such pair exists!" << endl;
    return false;
}

int main() {
    int n, sum; cin >> n >> sum;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        v.push_back(temp);
    }

    pairExists(v, v.size(), sum);

    return 0;
}
