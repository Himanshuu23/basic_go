/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// using recursive backtracking - Bron Kerbosch algorithm

int n;
vector<bitset<64>> adj;
int maxClique = 0;

void bronKerbosch(bitset<64> R, bitset<64> P, bitset<64> X) {
    if (P.none() && X.none()) {
        maxClique = max(maxClique, (int)R.count());
        return;
    }

    int u = (P | X)._Find_first();
    bitset<64> candidates = P & ~adj[u];

    for (int v = candidates._Find_first(); v < n; v = candidates._Find_next(v)) {
        bitset<64> newR = R;
        newR.set(v);
        bronKerbosch(newR, P & adj[v], X & adj[v]);
        P.reset(v);
        X.set(v);
    }
}

int main() {
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;
        for (int j = 0; j < d; ++j) {
            int v;
            cin >> v;
            adj[i][v] = 1;
        }
    }

    bitset<64> R, P, X;
    for (int i = 0; i < n; ++i) P.set(i);
    bronKerbosch(R, P, X);
    cout << "Max Clique Size: " << maxClique << "\n";
}
