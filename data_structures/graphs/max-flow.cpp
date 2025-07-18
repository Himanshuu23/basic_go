/*
    author: Himanshuu23
*/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define V 6

// ford fulkerson algo - use dfs to find an augmenting path. add flow along the path. Repeating until no more augmenting paths are found. - O(max_flow x E) where E -> number of edges

bool dfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, false, sizeof(visited));

    vector<int> st;
    st.push_back(s);
    visited[s] = true;
    parent[s] = -1;

    while (!st.empty()) {
        int u = st.back();
        st.pop_back();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0){
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                st.push_back(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(int graph[V][V], int s, int t) {
    int u, v;

    int rGraph[V][V];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (dfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        // Find min residual capacity in the path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }
    return max_flow;
}

// edmonds karp algorithm (bfs version of above method) - use bfs to find the shortest augmenting path (in terms of edges). Improves performance over naive dfs in ford-fulkerson. O(v x E2) 

bool bfs(int rGraph[V][V], int s, int t, int parent[]) {
    bool visited[V];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

int edmondsKarp(int graph[V][V], int s, int t) {
    int u, v;
    int rGraph[V][V];

    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int graph[V][V] = {
            {0, 16, 13, 0, 0, 0},
            {0, 0, 10, 12, 0, 0},
            {0, 4, 0, 0, 14, 0},
            {0, 0, 9, 0, 0, 20},
            {0, 0, 0, 7, 0, 4},
            {0, 0, 0, 0, 0, 0}
        };

        cout << "Maximum Flow using Ford-Fulkerson: " << fordFulkerson(graph, 0, 5) << endl;
        cout << "Maximum Flow using Edmonds-Karp: " << edmondsKarp(graph, 0, 5) << endl;
    }

    return 0;
}
