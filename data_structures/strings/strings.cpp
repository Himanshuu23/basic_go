#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    cout << str1 + str2 << endl;
    str1.append(str2);
    cout << str1 << endl;

    cout << str1[1] << endl;

    str1.clear();
    cout << str1 << endl;

    return 0;
}
