/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool hasCycle(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false);
    vector<bool> recStack(V, false);

    for (int start = 0; start < V; start++) {
        if (!visited[start]) {
            stack<int> st;
            vector<int> parent(V, -1);

            st.push(start);
            while (!st.empty()) {
                int node = st.top();

                if (!visited[node]) {
                    visited[node] = true;
                    recStack[node] = true;
                }

                bool pushedNeighbor = false;
                for (int neighbor : adj[node]) {
                    if (!visited[neighbor]) {
                        parent[neighbor] = node;
                        st.push(neighbor);
                        pushedNeighbor = true;
                        break;
                    } else if (recStack[neighbor]) return true; // cycle found
                }

                if (!pushedNeighbor) {
                    // backtracking
                    recStack[node] = false;
                    st.pop();
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int V = 4;
        vector<vector<int>> adj(V);

        adj[0].push_back(1);
        adj[1].push_back(2);
        adj[2].push_back(3);
        adj[3].push_back(1);

        if (hasCycle(V, adj))
            cout << "Cycle Detected" << endl;
        else
            cout << "No Cycle Detected" << endl;
    }

    return 0;
}
