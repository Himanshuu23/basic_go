/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> solve(int n, vector<vector<pair<int, int>>>& adj, int S) {
    vector<int> dist(n, INT_MAX);
    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n = 4;
        vector<vector<pair<int, int>>> adj(n);
        adj[0].push_back({1, 1});
        adj[0].push_back({2, 4});
        adj[1].push_back({2, 2});
        adj[1].push_back({3, 6});
        adj[2].push_back({3, 3});

        int source = 0;
        vector<int> result = solve(n, adj, source);
        for (int d : result) cout << d << " ";
        cout << "\n";
    }

    return 0;
}
