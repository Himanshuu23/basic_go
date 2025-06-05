#include <bits/stdc++.h>
using namespace std;

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 10;
    int *aptr = &a;
    int **ptrptr = &aptr;
    cout << aptr << " " << *aptr << endl;
    cout << ptrptr << " " << *ptrptr << " " << **ptrptr << endl;

    *aptr = 20;
    cout << a << endl;

    **ptrptr = 22;
    cout << a << endl;

    aptr += 2;
    cout << aptr << endl;

    int arr[] = { 10, 20, 30, 40, 50 };
    cout << *arr << " " << *(arr + 1) << " " << *(arr + 2) << endl;

    int *ptr = arr;
    cout << ptr << endl;

    for (int i = 0; i < 5; i++) {
        cout << *ptr << endl;
        ptr++;
    }

    int b = 44;
    cout << "Before swapping: " << a << " " << b << endl;
    swap(&a, &b);
    cout << "After swapping: " << a << " " << b << endl;

    return 0;
}
