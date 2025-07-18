/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5;

// using tarzan's algorithm - dfs with tim[u] - time node u is discovered, low[u] - earliest reachable ancestor from subtree rooted at u.
// a bridge is identified when low[v]>tin[u] means there is no back edge from v or its subtree back to any ancestor of u

vector<int> adj[N], tim(N), low(N);
vector<bool> visited(N);
int timer;
vector<pair<int, int>> bridges;

void dfs(int u, int parent = -1) {
    visited[u] = true;
    tim[u] = low[u] = timer++;

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (visited[v]) {
            low[u] = min(low[u], tim[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > tim[u]) bridges.push_back({u, v});
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n = 5;
        vector<pair<int, int>> edges = {{0,1}, {1,2}, {2,0}, {1,3}, {3,4}};
    
        bridges.clear();
        for (int i = 0; i < N; i++) adj[i].clear();

        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        fill(visited.begin(), visited.end(), false);
        timer = 0;

        for (int i = 0; i < n; i++) if (!visited[i]) dfs(i);

        for (auto [u, v] : bridges) cout << u << " - " << v << endl;
    }

    return 0;
}
