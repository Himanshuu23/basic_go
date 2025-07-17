/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> bfsShortestPath(int V, const vector<vector<int>>& adj, int src) {
    vector<int> dist(V, -1); // -1 means unreachable
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) { // not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // undirected graph
        }

        int src;
        cin >> src;

        vector<int> distances = bfsShortestPath(V, adj, src);

        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << " : Distance = " << distances[i] << "\n";
        }
    }

    return 0;
}
