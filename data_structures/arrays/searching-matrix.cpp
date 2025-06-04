#include <bits/stdc++.h>
using namespace std;


int main() {
    int rows, cols; cin >> rows >> cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int temp = 0; cin >> temp;
            matrix[i][j] = temp;
        }
        cout << endl;
    }

    int el;
    cout << "Enter the element you want to search: ";
    cin >> el;

    bool flag = false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == el) {
                flag = true;
            }
        }
    }

    if (flag) {
        cout << "Element Found!" << endl;
    } else {
        cout << "Couldn't find the element you're looking for." << endl;
    }

    return 0;
}
