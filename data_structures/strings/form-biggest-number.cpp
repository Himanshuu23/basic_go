#include <bits/stdc++.h>
using namespace std;

int main() {
    string num;
    getline(cin, num);

    sort(num.begin(), num.end(), greater<int>());
    cout << num << endl;

    return 0;
}
