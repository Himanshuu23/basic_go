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

node* reverse(node* head) {
    node* prev = NULL;
    while (head) {
        node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(node* head) {
    if (!head || !head->next) return true;

    node* slow = head, *fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    node* second = reverse(slow);
    node* first = head;

    while (second) {
        if (first->data != second->data) return false;
        first = first->next;
        second = second->next;
    }

    return true;
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
        head->next->next = new node(1);
        head->next->next->next = new node(0);
        display(head);
        if (isPalindrome(head)) cout << "It's a Palindrome" << endl;
        else cout << "Not a Palindrome" << endl;
    }

    return 0;
}
