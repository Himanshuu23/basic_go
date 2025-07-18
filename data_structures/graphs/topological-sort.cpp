/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Using Kahan's Algorithm - detects Cycles too!
// count in-degrees, push all 0 in-degrees to the queue and remove them one by one and reduce in-degree of their neighbors, if some nodes remain unprocessed - there's a cycle.

vector<int> kahan(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);
    for (auto& neighbors : adj)
        for (int v : neighbors) inDegree[v]++;
    
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0) q.push(i);

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) if (--inDegree[v] == 0) q.push(v);
    }

    if (topo.size() != n) return {}; // cycle detected

    return topo;
}

// dfs based solution 
// do dfs, push node to result after visiting all its neighbors -> reverse the result

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfs(v, adj, visited, st);
    st.push(u);
}

vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) if (!visited[i]) dfs(i, adj, visited, st);

    vector<int> topo;
    while (!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        vector<int> topo1 = kahan(n, adj);
        vector<int> topo2 = topoSortDFS(n, adj);

        if (topo1.empty())
            cout << "Kahan: Cycle detected\n";
        else {
            cout << "Kahan: ";
            for (int x : topo1) cout << x << ' ';
            cout << '\n';
        }

        cout << "DFS: ";
        for (int x : topo2) cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
