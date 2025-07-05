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

    node (int value) {
        data = value;
        next = NULL;
    }
};

node* recursion(node* &head) {
    if (head == NULL || head->next == NULL) return head;
    
    node* newHead = recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

node* reverse(node* &head) {
    node* prevptr = NULL;
    node* currptr = head;
    node *nextptr = NULL;
    while (currptr != NULL) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;
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
        node* head = new node(0);
        head->next = new node(1);
        head->next->next = new node(2);
        head->next->next->next = new node(3);
        display(head);
        head = reverse(head);
        display(head);
        head = recursion(head);
        display(head);
    }

    return 0;
}
