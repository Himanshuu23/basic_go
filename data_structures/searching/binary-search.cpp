#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target) {
            return binarySearch(arr, 0, mid - 1, target);
        } else if (arr[mid] > target) {
            return binarySearch(arr, mid + 1, end, target);
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << binarySearch(arr, 0, size, 3) << endl;
    cout << binarySearch(arr, 0, size, 8) << endl;
}
