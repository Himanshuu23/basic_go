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
        int n; cin >> n;
        node* head = NULL;
        for (int i = 0; i < n; i++) {
            int value; cin >> value;
            insertAtHead(head, value);
        }
        display(head);
    }

    return 0;
}
