/*
    author: Himanshuu23
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class node {
    public:
    int data;
    node* next;
    node* prev;
    node* child;

    node (int value) {
        data = value;
        next = NULL;
        prev = NULL;
        child = NULL;
    }
};

node* flatten(node* head) {
    if (!head) return head;

    node* curr = head;
    while (curr) {
        if (curr->child) {
            node* next = curr->next;
            node* child = flatten(curr->child);
            
            curr->next = child;
            child->prev = curr;
            curr->child = nullptr;

            while (curr->next) curr = curr->next;

            curr->next = next;
            if (next) next->prev = curr;
        }
        curr = curr->next;
    }

    return head;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    node* head = new node(1);
    head->next = new node(2);
    head->next->prev = head;
    head->next->next = new node(3);
    head->next->next->prev = head->next;

    head->next->next->child = new node(7);
    head->next->next->child->next = new node(8);
    head->next->next->child->next->prev = head->next->next->child;

    node* flat = flatten(head);

    while (flat) {
        cout << flat->data << " ";
        flat = flat->next;
    }
    cout << "\n";

    return 0;
}
