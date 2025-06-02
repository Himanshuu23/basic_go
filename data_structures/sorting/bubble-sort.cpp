#include <bits/stdc++.h>
using namespace std;

vector<int> bubbleSort(vector<int>& array) {
    int n = array.size();
    for (int counter = 0; counter < n - 1; counter++) {
        bool swapped = false;
        for (int i = 0; i < n - 1 - counter; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    return array;
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int elem;
        cin >> elem;
        v.push_back(elem);
    }

    bubbleSort(v);

    for (auto el : v) {
        cout << el << " ";
    }
    cout << endl;

    return 0;
}
