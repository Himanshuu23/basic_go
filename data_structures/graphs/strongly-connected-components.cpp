/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Kosaraju Algorithm (Twice DFS) - Do a DFS on original graph and store vertices in a stack according to their finish times. 
// Reverse the graph (reversing the direction of all the edges).
// Do DFS again -> this time in the order of stack but on the reversed stack. Each DFS run will give one SCC
// O(V + E)

void dfs1(int node, vector<vector<int>> &graph, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int nbr : graph[node])
        if (!visited[nbr]) dfs1(nbr, graph, visited, st);
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& revGraph, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);
    for (int nbr : revGraph[node])
        if (!visited[nbr]) dfs2(nbr, revGraph, visited, component);
}

void kosaraju(int V, vector<vector<int>>& graph) {
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) { // filling the graph with finishing times
        if (!visited[i]) dfs1(i, graph, visited, st);    
    } 

    // reversing the graph
    vector<vector<int>> revGraph(V);
    for (int u = 0; u < V; u++)
        for (int v : graph[u]) revGraph[v].push_back(u);

    // doing dfs in stack order on reversed graph
    fill(visited.begin(), visited.end(), false);
    cout << "Strongly Connected Components:\n";
    while (!st.empty()) {
        int node = st.top(); st.pop();
        if (!visited[node]) {
            vector<int> component;
            dfs2(node, revGraph, visited, component);
            for (int v : component) cout << v << " ";
            cout << endl;
        }
    }
}

// Tarjan's Algorithm (Single DFS) - Uses low-link values: smallest vertex id reachable from the subtree rooted at that node.
// Maintains a stack of visited nodes and a desc[] and low[] array. Whenever disc[u] == low[u], it's head nodes of an SCC
// O(V + E)
int timer = 0;

void tarjanDFS(int u, vector<vector<int>>& graph, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& inStack, vector<vector<int>>& SCCs) {
    disc[u] = low[u] = timer++;
    st.push(u);
    inStack[u] = true;

    for (int v : graph[u]) {
        if (disc[v] == -1) {
            tarjanDFS(v, graph, disc, low, st, inStack, SCCs);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) low[u] = min(low[u], disc[v]);
    }

    if (disc[u] == low[u]) {
        vector<int> component;
        int v;
        do {
            v = st.top(); st.pop();
            inStack[v] = false;
            component.push_back(v);
        } while (u != v);
        SCCs.push_back(component);
    }
}

void tarjan(int V, vector<vector<int>>& graph) {
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> st;
    vector<vector<int>> SCCs;

    for (int i = 0; i < V; i++)
        if (disc[i] == -1) tarjanDFS(i, graph, disc, low, st, inStack, SCCs);

    cout << "Strongly Connected Components:\n";
    for (auto &component : SCCs) {
        for (int v : component) cout << v << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int V = 5;
        vector<vector<int>> graph(V);
        graph[0] = {1};
        graph[1] = {2};
        graph[2] = {0, 3};
        graph[3] = {4};
        graph[4] = {};

        kosaraju(V, graph);
        tarjan(V, graph);
    }

    return 0;
}
