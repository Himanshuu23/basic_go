/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void dfs(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) dfs(neighbor, adj, visited);
    }
}

int countConnectedComponents(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            count++;
        }
    }

    return count;
}

int bfsCountConnectedComponents(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    int count = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }

            count++;
        }
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int V = 6;
        vector<vector<int>> adj(V);

        vector<pair<int, int>> edges = {
            {0, 1}, {1, 2}, {3, 4}
        };

        for (auto [u, v] : edges) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int result_dfs = countConnectedComponents(V, adj);
        cout << "DFS: Number of connected components: " << result_dfs << endl;

        int result_bfs = bfsCountConnectedComponents(V, adj);
        cout << "BFS: Number of connected components: " << result_bfs << endl;
    }

    return 0;
}
