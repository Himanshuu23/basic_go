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

    node (int val) {
        data = val;
        next = NULL;
    }
};

void insertAtHead(node* &head, int val) {
    node* n = new node(val);
    
    if (head == NULL) {
        head = n;
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = n;
}

void deleteHead(node* &head) {
    node* toDelete = head;
    head = head->next;
    delete toDelete;
}

void deleteNode(node* &head, int value) {
    if (head == NULL) return;
    if (head->next == NULL) deleteHead(head);
    node* temp = head;
    while (temp->next->data != value) temp = temp->next;
    node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}

void display(node* &head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        node* head = NULL;
        insertAtHead(head, 1);
        insertAtHead(head, 2);
        insertAtHead(head, 3);
        display(head);
        deleteNode(head, 2);
        display(head);
    }

    return 0;
}
