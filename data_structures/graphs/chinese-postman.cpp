/*
    author: Himanshuu23
*/

// for undirected only - check if the graph is eulerian (all vertices have even degree), if not find odd vertices.
// pair odd degree vertices to minimize added path cost, add those paths to make degrees even -> eulerian now -> apply heirholzer's algorithm

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, INF));
    vector<int> degree(n, 0);
    int totalWeight = 0;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = adj[v][u] = min(adj[u][v], w);
        degree[u]++; degree[v]++;
        totalWeight += w;
    }

    // Floyd-Warshall for all-pairs shortest paths
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    vector<int> odd;
    for (int i = 0; i < n; ++i)
        if (degree[i] % 2) odd.push_back(i);

    int sz = odd.size();
    vector<int> dp(1 << sz, INF);
    dp[0] = 0;

    for (int mask = 0; mask < (1 << sz); ++mask) {
        if (__builtin_popcount(mask) % 2) continue;
        for (int i = 0; i < sz; ++i) {
            if (!(mask & (1 << i))) {
                for (int j = i + 1; j < sz; ++j) {
                    if (!(mask & (1 << j))) {
                        int next = mask | (1 << i) | (1 << j);
                        dp[next] = min(dp[next], dp[mask] + adj[odd[i]][odd[j]]);
                    }
                }
                break;
            }
        }
    }

    cout << "Minimum route cost: " << totalWeight + dp[(1 << sz) - 1] << "\n";
    return 0;
}
