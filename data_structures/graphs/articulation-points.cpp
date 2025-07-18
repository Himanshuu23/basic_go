/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5;

// tarjan's algorithm - tim[u] -> time node u is discovered, low[u] earliest reachable ancestor from subtree rooted at u.
// // then a node is articulation point if low[v] >= tin[u] --> for any child v and u is not root, or u is the root and has >=2 dfs children

vector<int> adj[N], tim(N), low(N);
bool visited[N];
int timer;
set<int> articulationPoints;

void dfs(int u, int parent = -1) {
    visited[u] = true;
    tim[u] = low[u] = timer++;
    int children(0);

    for (int v : adj[u]) {
        if (v == parent) continue;

        if (visited[v]) low[u] = min(low[u], tim[v]); // back edge
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            
            if (low[v] >= tim[u] && parent != -1) articulationPoints.insert(u);
            children++;
        }
    }

    // special case for root
    if (parent == -1 && children > 1) articulationPoints.insert(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n = 5;
        vector<pair<int, int>> edges = {{0,1}, {1,2}, {2,0}, {1,3}, {3,4}};
        
        articulationPoints.clear();
        for (int i = 0; i < N; i++) adj[i].clear();
        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        memset(visited, false, sizeof(visited));
        timer = 0;

        for (int i = 0; i < n; i++) if (!visited[i]) dfs(i);

        for (int p : articulationPoints) cout << p << " ";
        cout << endl;
    }

    return 0;
}
