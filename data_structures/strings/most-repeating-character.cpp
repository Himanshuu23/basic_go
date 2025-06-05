#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    vector<int> freq(26, 0);

    for (int i = 0; i < str.size(); i++) {
        freq[str[i] - 'a']++;
    }

    char ans = 'a';
    int maxFreq = 0;
    for (int i = 0; i < str.size(); i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            ans = i + 'a';
        }
    }

    cout << maxFreq << " " << ans << endl;

    return 0;
}
