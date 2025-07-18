/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = INT_MAX;

// dp + bitmasking - Held Karp Algo - use a bitmask to represent the set of visited cities, and let dp[mask][u] = minimum cost to reach city u having visiting cities in mask
// try going from every prev city to u if not visited yet
// base case - dp[1<<0][0] = 0 - starting from city 0 with 0 cities visited

int tsp(int n, vector<vector<int>>& dist) {
    int VISITED_ALL = (1 << n) - 1;
    vector<vector<int>> dp(1 << n, vector<int>(n, INF));

    dp[1 << 0][0] = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; ++v) {
                    if (!(mask & (1 << v))) {
                        int nextMask = mask | (1 << v);
                        if (dp[mask][u] != INF)
                            dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
                    }
                }
            }
        }
    }

    int minCost = INF;
    for (int u = 1; u < n; ++u) {
        if (dp[VISITED_ALL][u] != INF)
            minCost = min(minCost, dp[VISITED_ALL][u] + dist[u][0]);
    }

    return minCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        vector<vector<int>> dist = {
            {0, 10, 15, 20},
            {10, 0, 35, 25},
            {15, 35, 0, 30},
            {20, 25, 30, 0}
        };
        cout << tsp(4, dist) << endl;
    }

    return 0;
}
