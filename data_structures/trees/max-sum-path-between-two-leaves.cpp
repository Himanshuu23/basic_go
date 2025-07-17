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

int helper(Node* root, int& maxSum) {
    if (!root) return 0;

    // if lead node return its value
    if (!root->left && !root->right) return root->data;
    
    // recursing on left and right
    int leftSum = helper(root->left, maxSum);
    int rightSum = helper(root->right, maxSum);
    
    // if both children present, this can be connector between two leaves
    if (root->left && root->right) {
        int leafToLeaf = leftSum + rightSum + root->data;
        maxSum = max(maxSum, leafToLeaf);

        // return max path downward to parent
        return max(leftSum, rightSum) + root->data;
    }

    // if only one child
    return (root->left ? leftSum : rightSum) + root->data;
}

int solve(Node* root) {
    int maxSum = INT_MIN;
    helper(root, maxSum);
    return maxSum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(-15);
        root->left = new Node(5);
        root->right = new Node(6);
        root->right->left = new Node(-8);
        root->right->right = new Node(1);
        root->right->left->left = new Node(2);
        root->right->left->right = new Node(6);
        cout << solve(root) << endl;
    }

    return 0;
}
