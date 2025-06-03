#include <bits/stdc++.h>
using namespace std;

vector<int> insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int curr = arr[i];
        int j = i - 1;
        while((arr[j] > curr) && (j >= 0)) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }

    return arr;
}

int main() {
    vector<int> a = { 5, 4, 3, 2, 1 };
    insertionSort(a);

    for (auto el : a) {
        cout << el << " "; 
    }

    return 0;
}
