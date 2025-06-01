#include "bits/stdc++.h"
using namespace std;

bool canPlace(const vector<int>& stalls, int cows, int dist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); ++i) {
        if (stalls[i] - last >= dist) {
            ++count;
            last = stalls[i];
        }
    }
    return count >= cows;
}

int minDistance(int N, int C, vector<int>& loc) {
    sort(loc.begin(), loc.end());
    int low = 1, high = loc.back() - loc[0], result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canPlace(loc, C, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> loc(N);
    for (int i = 0; i < N; ++i) {
        cin >> loc[i];
    }

    cout << minDistance(N, C, loc) << endl;
}
