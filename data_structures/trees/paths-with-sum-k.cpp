/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node (int val) : data(val), left(nullptr), right(nullptr) {}
};

int countFromNode(Node* root, int k) {
    if (!root) return 0;

    int count = 0;
    if (root->data == k) count++;

    count += countFromNode(root->left, k - root->data);
    count += countFromNode(root->right, k - root->data);

    return count;
}

int countPaths(Node* root, int k) {
    if (!root) return 0;

    int count = countFromNode(root, k);

    count += countPaths(root->left, k);
    count += countPaths(root->right, k);

    return count;
}

void dfs(Node* root, int currSum, int k, unordered_map<int, int>& prefixSumCount, int& totalPaths) {
    if (!root) return;
    
    currSum += root->data;
    if (prefixSumCount.count(currSum -k)) totalPaths += prefixSumCount[currSum - k];
    
    prefixSumCount[currSum]++;
    
    dfs(root->left, currSum, k, prefixSumCount, totalPaths);
    dfs(root->right, currSum, k, prefixSumCount, totalPaths);
    
    // backtracking
    prefixSumCount[currSum]--;
}

int countPath(Node* root, int k) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int totalPaths = 0;
    dfs(root, 0, k, prefixSumCount, totalPaths);
    return totalPaths;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(1);
        root->left = new Node(3);
        root->right = new Node(-1);
        root->left->left = new Node(2);
        root->left->right = new Node(1);
        root->left->right->right = new Node(1);
        root->right->left = new Node(4);
        root->right->right = new Node(5);

        cout << countPaths(root, 5) << endl;
        cout << countPath(root, 5) << endl;
    }

    return 0;
}
