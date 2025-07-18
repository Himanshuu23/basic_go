/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;

// dp + topological sort

void topologicalSort(int u, vector<bool>& visited, stack<int>& st, vector<pair<int, int>> adj[]) {
    visited[u] = true;
    for (auto& [v, w] : adj[u]) {
        if (!visited[v])
            topologicalSort(v, visited, st, adj);
    }
    st.push(u);
}

void longestPath(int N, vector<pair<int, int>> adj[], int src) {
    vector<bool> visited(N, false);
    stack<int> st;

    for (int i = 0; i < N; i++)
        if (!visited[i])
            topologicalSort(i, visited, st, adj);

    vector<int> dist(N, -INF);
    dist[src] = 0;

    while (!st.empty()) {
        int u = st.top(); st.pop();

        if (dist[u] != -INF) {
            for (auto& [v, w] : adj[u])
                if (dist[v] < dist[u] + w)
                    dist[v] = dist[u] + w;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << "Longest distance to " << i << " = ";
        if (dist[i] == -INF) cout << "Unreachable\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int N = 6;
        vector<pair<int, int>> adj[N];

        adj[0].push_back({1, 5});
        adj[0].push_back({2, 3});
        adj[1].push_back({3, 6});
        adj[1].push_back({2, 2});
        adj[2].push_back({4, 4});
        adj[2].push_back({5, 2});
        adj[2].push_back({3, 7});
        adj[3].push_back({5, 1});
        adj[4].push_back({5, -1});

        int source = 1;
        longestPath(N, adj, source);
    }

    return 0;
}
