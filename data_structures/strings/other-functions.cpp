#include <bits/stdc++.h>
using namespace std;

int main() {
    string str = "this is a string";
    string num = "123";

    cout << str.find("is") << endl;

    str.insert(3, "another substring");

    cout << str << endl;
    cout << str.size() << endl;

    for (int i = 0; i < str.size(); i++) {
        cout << str[i] << " ";
    }

    cout << endl;
    cout << str.substr(6, 4) << endl;

    int x = stoi(num);
    cout << x + 2 << endl;
    cout << to_string(x) + "4" << endl;
}
