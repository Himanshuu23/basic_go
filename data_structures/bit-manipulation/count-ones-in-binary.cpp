#include <bits/stdc++.h>
using namespace std;

int countNumberOfOnes(int n) {
    int count = 0;

    while(n) {
        n = n & n-1;
        count++;
    }

    return count;
}

int main() {
    
    cout << countNumberOfOnes(19) << endl;
    return 0;
}
