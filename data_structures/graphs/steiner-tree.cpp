/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// only for smaller inputs - less than 20 terminal
// use dreyfus-wagner dp for terminal sets upto 15 nodes, use bitmask dp to build min trees

const int INF = 1e9;
const int MAXN = 100;

int dist[MAXN][MAXN];

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> terminals(k);

    for (int i = 0; i < k; ++i)
        cin >> terminals[i];

    // Init distances
    for (int i = 0; i < n; ++i)
        fill(dist[i], dist[i] + n, INF), dist[i][i] = 0;

    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = dist[v][u] = min(dist[u][v], w);
    }

    // Floyd-Warshall
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int T = terminals.size();
    vector<vector<int>> dp(1 << T, vector<int>(n, INF));

    for (int i = 0; i < T; ++i)
        for (int v = 0; v < n; ++v)
            dp[1 << i][v] = dist[terminals[i]][v];

    for (int mask = 1; mask < (1 << T); ++mask) {
        for (int sub = mask & (mask - 1); sub; sub = (sub - 1) & mask) {
            int other = mask ^ sub;
            for (int v = 0; v < n; ++v)
                dp[mask][v] = min(dp[mask][v], dp[sub][v] + dp[other][v]);
        }
        for (int u = 0; u < n; ++u)
            for (int v = 0; v < n; ++v)
                dp[mask][v] = min(dp[mask][v], dp[mask][u] + dist[u][v]);
    }

    int result = *min_element(dp[(1 << T) - 1].begin(), dp[(1 << T) - 1].end());
    cout << "Minimum Steiner Tree cost: " << result << "\n";
}
