#include <bits/stdc++.h>
using namespace std;

void toUpperCase(string word) {
    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            word[i] -= 32;
        }
    }

    cout << word << endl;
}

void toLowerCase(string word) {
    for (int i = 0; i < word.size(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] += 32;
        }
    }

    cout << word << endl;
}


int main () {
    string str;
    getline(cin, str);

    toUpperCase(str);
    toLowerCase(str);

    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << str << endl;

    return 0;
}
