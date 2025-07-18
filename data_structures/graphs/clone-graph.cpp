/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

// approach - DFS --> using a hash map to track already created cloned nodes, recurse into each neighbor and clone them.

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() : val(0), neighbors({}) {}
    Node(int _val) : val(_val), neighbors({}) {}
    Node(int _val, vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

class Solution {
    unordered_map<Node*, Node*> cloned;

public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        if (cloned.count(node)) return cloned[node];

        Node* copy = new Node(node->val);
        cloned[node] = copy;

        for (Node* neighbor : node->neighbors)
            copy->neighbors.push_back(cloneGraph(neighbor));

        return copy;
    }
};

Node* buildGraph() {
    int n; cin >> n;
    vector<Node*> nodes(n + 1, nullptr);

    for (int i = 1; i <= n; i++) nodes[i] = new Node(i);

    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            int neighborVal; cin >> neighborVal;
            nodes[i]->neighbors.push_back(nodes[neighborVal]);
        }
    }

    return nodes[1];
}

void printGraph(Node* node) {
    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(node);
    visited.insert(node);

    while (!q.empty()) {
        Node* curr = q.front(); q.pop();
        cout << "Node " << curr->val << ": ";
        for (Node* nbr : curr->neighbors) {
            cout << nbr->val << " ";
            if (!visited.count(nbr)) {
                visited.insert(nbr);
                q.push(nbr);
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* start = buildGraph();
        Solution sol;
        Node* cloned = sol.cloneGraph(start);
        printGraph(cloned);
    }

    return 0;
}
