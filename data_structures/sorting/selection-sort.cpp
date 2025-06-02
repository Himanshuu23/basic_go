#include <bits/stdc++.h>
using namespace std;

vector<int> selectionSort(vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
    return array;
}

int main() {
    vector<int> v = {1, 2, 4, 5};
    vector<int> sorted = selectionSort(v);

    for (int num : sorted) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
