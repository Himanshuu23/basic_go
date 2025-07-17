/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> parent;

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

bool unionSets(int u, int v) {
    int pu = find(u), pv = find(v);
    if (pu == pv) return true;
    parent[pu] = parent[pv];
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        parent.resize(V);
        for (int i = 0; i < V; ++i)
            parent[i] = i;

        bool hasCycle = false;
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;

            if (unionSets(u, v)) {
                hasCycle = true;
                break;
            }
        }

        if (hasCycle)
            cout << "Cycle detected\n";
        else
            cout << "No cycle\n";
    }

    return 0;
}
