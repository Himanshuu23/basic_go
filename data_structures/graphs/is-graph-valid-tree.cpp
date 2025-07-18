/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// approach - union-find --> if any edge, connect two nodes in the same set -> cycle. After processing all edges, check if there's exactly one connected component

int find(int u, vector<int>& parent) {
    if (parent[u] != u) parent[u] = find(parent[u], parent);
    return parent[u];
}

bool unionSets(int u, int v, vector<int>& parent) {
    int pu = find(u, parent);
    int pv = find(v, parent);
    if (pu == pv) return false;
    parent[pu] = pv;
    return true;
}

bool solve(int n, vector<vector<int>>& edges) {
    if (edges.size() != n - 1) return false;

    vector<int> parent(n);
    for (int i = 0; i < n; i++) parent[i] = i;
    for (auto& edge : edges) {
        if (!unionSets(edge[0], edge[1], parent)) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            edges[i] = {u, v};
        }

        cout << ((solve(n, edges)) ? "Yes" : "No") << endl;
    }

    return 0;
}
