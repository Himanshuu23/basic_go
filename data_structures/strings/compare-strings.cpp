#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    if (!(s2.compare(s1))) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are unequal" << endl;
    }

    return 0;
}
