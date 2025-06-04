#include <bits/stdc++.h>
using namespace std;

int main() {
    int row1, col1, col2; cin >> row1 >> col1 >> col2;
    vector<vector<int>> matrix1(row1, vector<int>(col1));
    vector<vector<int>> matrix2(col1, vector<int>(col2));
    vector<vector<int>> ans(row1, vector<int>(col2));

    cout << "Enter the elements of the first array" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            int temp = 0; cin >> temp;
            matrix1[i][j] = temp;
        }
        cout << "enter next row now" << endl;
    }
    
    cout << "Enter the elements of the second array" << endl;
    for (int i = 0; i < col1; i++) {
        for (int j = 0; j < col2; j++) {
            int temp = 0; cin >> temp;
            matrix2[i][j] = temp;
        }
        cout << "enter next row now" << endl;
    }
    
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                ans[i][j] += (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
