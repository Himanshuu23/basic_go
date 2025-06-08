#include <bits/stdc++.h>
using namespace std;

int findUnique(int arr[], int n, int k) {
    int result = 0;

    for (int i = 0; i < 32; i++) {
        int sum = 0;
        int bitMask = (1 << i);

        for (int j = 0; j < n; j++) {
            if (arr[j] & bitMask)
                sum++;
        }

        if (sum % k != 0)
            result |= bitMask;
    }

    return result;
}

int main() {
    int arr[] = {6, 1, 3, 3, 3, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    cout << "The unique number is: " << findUnique(arr, n, k) << endl;

    return 0;
}
