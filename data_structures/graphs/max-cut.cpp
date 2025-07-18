/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Goemans-Williamson gives good approx via semidefinite programming (hard to implement).

int maxCut(const vector<vector<int>>& graph) {
    int n = graph.size(), maxVal = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int curr = 0;
        for (int u = 0; u < n; ++u) {
            for (int v = u + 1; v < n; ++v) {
                if ((mask >> u & 1) != (mask >> v & 1))
                    curr += graph[u][v];
            }
        }
        maxVal = max(maxVal, curr);
    }
    return maxVal;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            cin >> graph[u][v];
    cout << "Max Cut Value: " << maxCut(graph) << "\n";
}
