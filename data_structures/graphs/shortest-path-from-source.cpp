/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Dijkstra - directed + undirected, no negative cycles though -> (V+E)logV --> 

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

vector<int> bellmanFord(int n, vector<tuple<int, int, int>>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) dist[v] = dist[u] + w;
        }
    }

    // for detecting negative cycles
    for (auto& [u, v, w] : edges) 
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) throw runtime_error("Negative weight cycle detected!");
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<pair<int, int>>> adj(n);
        vector<tuple<int, int, int>> edges;

        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            adj[u].push_back({v, w});
            edges.emplace_back(u, v, w);
        }

        int src; cin >> src;

        auto d1 = dijkstra(n, adj, src);
        auto d2 = bellmanFord(n, edges, src);

        cout << "Dijkstra: ";
        for (int d : d1) cout << d << " "; cout << endl;
    
        cout << "Bellman-Ford: ";
        for (int d : d2) cout << d << " "; cout << endl;
    }

    return 0;
}
