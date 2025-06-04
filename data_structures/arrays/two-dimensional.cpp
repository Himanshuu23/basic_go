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
        cout << "enter next row now" << endl;
    }


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
