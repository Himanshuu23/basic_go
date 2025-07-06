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
    node* prev_group_tail = &dummy;

    while (true) {
        node* kth = prev_group_tail;
        for (int i = 0; i < k && kth; i++)
            kth = kth->next;

        if (!kth) break;

        node* group_start = prev_group_tail->next;
        node* next_group_head = kth->next;

        node* prev = kth->next;
        node* curr = group_start;

        while (curr != next_group_head) {
            node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        prev_group_tail->next = kth;
        prev_group_tail = group_start;
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
