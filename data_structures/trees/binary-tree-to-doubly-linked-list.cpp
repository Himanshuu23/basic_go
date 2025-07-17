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

// Helper function to perform in-order traversal and build DLL
void convertToDLL(Node* root, Node*& prev, Node*& head) {
    if (!root) return;

    // Recurse on left subtree
    convertToDLL(root->left, prev, head);

    // Process current node
    if (!prev) {
        // First node visited (leftmost) becomes head of DLL
        head = root;
    } else {
        prev->right = root;   // Link previous node to current
        root->left = prev;    // Link current to previous
    }
    prev = root; // Move prev to current

    // Recurse on right subtree
    convertToDLL(root->right, prev, head);
}

// Main function to call from driver
Node* binaryTreeToDLL(Node* root) {
    Node* head = nullptr;
    Node* prev = nullptr;
    convertToDLL(root, prev, head);
    return head;
}

// Utility function to print the DLL
void printDLL(Node* head) {
    cout << "Doubly Linked List (in-order): ";
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        Node* root = new Node(10);
        root->left = new Node(5);
        root->right = new Node(20);
        root->right->left = new Node(15);
        root->right->right = new Node(25);

        Node* dllHead = binaryTreeToDLL(root);
        printDLL(dllHead);
    }

    return 0;
}
