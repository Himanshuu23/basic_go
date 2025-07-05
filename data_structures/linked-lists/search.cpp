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

string search(node* &head, int value) {
    node* temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            return "Found\n";
        }
        temp = temp->next;
    }
    return "Not Found\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        node* head = NULL;
        insertAtHead(head, 1);
        insertAtHead(head, 2);
        cout << search(head, 3);
        cout << search(head, 2);
    }

    return 0;
}
