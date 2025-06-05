#include <bits/stdc++.h>
using namespace std;

void isEmpty(string str) {
    if (str.empty()) {
        cout << "String is empty" << endl;
    } else {
        cout << "String is not empty" << endl;
    }
}

int main() {
    string s1;
    getline(cin, s1);

    isEmpty(s1);
    s1.clear();
    isEmpty(s1);

    return 0;
}
