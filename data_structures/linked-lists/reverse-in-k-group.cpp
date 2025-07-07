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

node* reverseKGroup(node* head, int k) {
    if (!head || k == 1) return head;

    node dummy(0);
    dummy.next = head;
    node* prev = &dummy;

    while (true) {
        node* curr = prev;
        for (int i = 0; i < k && curr; ++i) curr = curr->next;
        if (!curr) break;

        node* tail = prev->next;
        node* next = curr->next;

        node* p = tail;
        node* q = p->next;

        while (q != next) {
            node* temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }

        prev->next = curr;
        tail->next = next;
        prev = tail;
    }

    return dummy.next;
}

void display(node* &head) {
    node* temp = head;
    while (temp) {
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
        head->next->next = new node(3);
        head->next->next->next = new node(4);
        display(head);
        head = reverseKGroup(head, 2);
        display(head);
    }

    return 0;
}
