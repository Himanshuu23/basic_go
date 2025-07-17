/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int V, E; cin >> V >> E;
        vector<vector<int>> adj(V, vector<int>(V, 0));

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
