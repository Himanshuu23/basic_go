#include <bits/stdc++.h>
using namespace std;

void findUnique(int arr[], int n) {
    int xorSum = 0;
    for (int i = 0; i < n; i++) {
        xorSum ^= arr[i];
    } // the result would be just XOR of the two elements only

    int setBit = xorSum & ~(xorSum - 1); // finding the element where these two differ by that bit

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) { // partitioning by that bit into two groups to find each unique number
        if (setBit & arr[i]) {
            x ^= arr[i];
        } else {
            y ^= arr[i];
        }
    }

    cout << "The unique numbers are: " << x << " and " << y << endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 1, 4 };
    findUnique(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}
