/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// using Kruskal's Algo - sort edges by weight, pick smallest edge that doesn't form a cyle - Union-Find approach

int find(int u, vector<int>& parent) {
    return parent[u] == u ? u : parent[u] = find(parent[u], parent);
}

bool unionSets(int u, int v, vector<int>& parent) {
    int pu = find(u, parent), pv = find(v, parent);
    if (pu == pv) return false;
    parent[pv] = pu;
    return true;
}

int kruskal(int n, vector<tuple<int, int, int>>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    int cost(0), count(0);
    
    for(auto& [w, u, v] : edges) {
        if (unionSets(u, v, parent)) {
            cost += w;
            count++;
            if (count == n - 1) break;
        }
    }

    return (count == n - 1) ? cost : -1;
}

// using Prim's - start from any node, always pick the smallest edge that connects to unvisited node - min heap

int prim(int n, vector<vector<pair<int, int>>>& adj) {
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});
    int cost = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cost += w;
        for (auto& [v, wt] : adj[u]) {
            if (!visited[v]) pq.push({wt, v});
        }
    }

    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<tuple<int, int, int>> edges;
        vector<vector<pair<int, int>>> adj(n);
        
        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            edges.push_back({w, u, v});
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        cout << "using kruskal: " << kruskal(n, edges) << endl;
        cout << "using prim: " << prim(n, adj) << endl;
    }

    return 0;
}
