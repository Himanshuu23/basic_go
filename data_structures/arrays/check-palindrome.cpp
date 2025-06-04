#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    char word[n+1];
    cin >> word;

    bool flag = 1;
    for (int i = 0; i < n; i++) {
        if (word[i] != word[n-1-i]) {
            flag = 0;
            break;
        }
    }

    if (flag) {
        cout << "the word is a palindrome" << endl;
    } else {
        cout << "the word isn't a palindrome" << endl;
    }

    return 0;
}
