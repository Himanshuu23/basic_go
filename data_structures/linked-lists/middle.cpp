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

int middle(node* &head) {
    node* ptr1 = head;
    node* ptr2 = head;

    while(ptr1 != NULL && ptr1->next != NULL) {
        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next;
    }
    return ptr2->data;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long t; cin >> t;
    while(t--) {
        node* head = new node(0);
        head->next = new node(1);
        head->next->next = new node(2);
        cout << middle(head) << endl;
        head->next->next->next = new node(3);
        cout << middle(head) << endl;
    }

    return 0;
}
