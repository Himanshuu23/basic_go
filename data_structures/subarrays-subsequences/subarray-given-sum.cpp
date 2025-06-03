#include <bits/stdc++.h>
using namespace std;

/*
If prefix[j] - prefix[i] = sum, then the subarray from i+1 to j sums to sum.
So we store prefix sums in a hash map as we go.

Approach - hash maps + prefix sum
*/

pair<int, int> subarraySum(vector<int>& arr, int n, int sum) {
    unordered_map<int, int> mp;
    int prefix = 0;

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (prefix == sum) {
            return { 0, i };
        }

        if (mp.count(prefix - sum)) {
            return { mp[prefix - sum] + 1, i }; 
        }

        mp[prefix] = i;
    }

    return { -1, -1 };
}

int main() {
    int n, sum; cin >> n >> sum;
    vector<int> array;

    for (int i = 0; i < n; i++) {
        int temp = 0; cin >> temp;
        array.push_back(temp);
    }

    pair<int, int> ans = subarraySum(array, array.size(), sum);

    if ((ans.first != -1) && (ans.second != -1)) {
        cout << ans.first << " " << ans.second << endl;
    } else {
        cout << "No such pair was found" << endl;
    }

    return 0;
}
