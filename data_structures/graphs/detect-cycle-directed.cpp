/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool hasCycle(int V, const vector<vector<int>>& adj) {
    vector<bool> visited(V, false); // marks if a node has been visited
    vector<bool> recStack(V, false); // marks if a node is on the current DFS path -> if any node repeating that is already in the stack - cycle found!

    for (int start = 0; start < V; start++) { // looping over all vertices , if the current hasn't been visited yet we perform DFS from that node
        if (!visited[start]) {
            stack<int> st; // stack to stimulate DFS
            vector<int> parent(V, -1); // helps keep track of the traversal path

            st.push(start);
            while (!st.empty()) { // starting DFS
                int node = st.top();

                if (!visited[node]) {
                    visited[node] = true;
                    recStack[node] = true; // mark node as part of the current path
                }

                bool pushedNeighbor = false;
                for (int neighbor : adj[node]) { // looping through all the neighbors of the current node
                    if (!visited[neighbor]) {
                        parent[neighbor] = node;
                        st.push(neighbor);
                        pushedNeighbor = true; // since we would go deeper into this node -> to its neighbor too by pushing this in the stack
                        break; // only going to one node at a time so breaking 
                    } else if (recStack[neighbor]) return true; // if neighbor already in the current recursion stack - cycle found
                }

                if (!pushedNeighbor) { // if we haven't pushed the node in the stack - we have processed this node - removing it from recursion stack - backtracking 
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

/*
 We perform a DFS traversal from every unvisited node.
While doing DFS:
    We maintain a recStack[] array (also called recursion stack or active path).
    If we visit a neighbor that is already in the recStack, a cycle exists.
    We use a manual stack instead of function recursion to simulate DFS.

 * */
