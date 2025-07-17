/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
typedef long long ll;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// building the graph and finding the target node - using graph coz in tree can only move left, right not children to parent
void buildGraph(Node* root, unordered_map<Node*, vector<Node*>>& adj, Node*& targetNode, int target) {
    if (!root) return;

    if (root->data == target) targetNode = root;

    if (root->left) {
        adj[root].push_back(root->left);
        adj[root->left].push_back(root);
        buildGraph(root->left, adj, targetNode, target);
    }

    if (root->right) {
        adj[root].push_back(root->right);
        adj[root->right].push_back(root);
        buildGraph(root->right, adj, targetNode, target);
    }
}

// BFS to stimulate fire spreading -> multi directional fire spreading simulation but making sure it is level by level in graph
int burnTree(Node* root, int target) {
    unordered_map<Node*, vector<Node*>> adj;
    Node* targetNode = nullptr;

    buildGraph(root, adj, targetNode, target);
    if (!targetNode) return 0;

    unordered_set<Node*> visited;
    queue<Node*> q;
    q.push(targetNode);
    visited.insert(targetNode);

    int time = -1;

    while (!q.empty()) {
        int size = q.size();
        time++;

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            for (Node* neighbor : adj[curr]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
    }

    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        int target = 5;
        cout << burnTree(root, target) << endl;
    }

    return 0;
}
