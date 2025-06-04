#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    char arr[n + 1];
    cin.getline(arr, n + 1);

    int i = 0, currLength = 0, maxLength = 0;
    int st = 0, maxSt = 0;

    while (true) {
        if (arr[i] == ' ' || arr[i] == '\0') {
            if (currLength > maxLength) {
                maxLength = currLength;
                maxSt = st;
            }
            currLength = 0;
            st = i + 1;
        } else {
            currLength++;
        }

        if (arr[i] == '\0') break;
        i++;
    }

    cout << "Longest word: ";
    for (int j = 0; j < maxLength; j++) {
        cout << arr[maxSt + j];
    }
    cout << "\nLength: " << maxLength << endl;

    return 0;
}
