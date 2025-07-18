/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// approach - using Kahan's Algorithm - (BFS + Topological Sort)

bool canFinish(int numCourse, vector<vector<int>>& prereq) {
    vector<vector<int>> adj(numCourse);
    vector<int> inDegree(numCourse, 0);

    for (auto& p : prereq) {
        adj[p[1]].push_back(p[0]);
        inDegree[p[0]]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourse; i++) 
        if (inDegree[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        count++;
        for (int v : adj[u])
            if (--inDegree[v] == 0) q.push(v);
    }

    return count == numCourse;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> pre(m);
        for (int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            pre[i] = {a, b};
        }

        cout << (canFinish(n, pre) ? "Yes" : "No") << endl;
    }

    return 0;
}
