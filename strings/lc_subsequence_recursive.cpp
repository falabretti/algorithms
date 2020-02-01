#include <bits/stdc++.h>
using namespace std;

int lc_subsequence(string a, string b) {
    int size_a = a.size();
    int size_b = b.size();

    if (size_a == 0 or size_b == 0) return 0;

    if (a[size_a - 1] == b[size_b - 1])
        return 1 +
               lc_subsequence(a.substr(0, size_a - 1), b.substr(0, size_b - 1));
    else
        return max(lc_subsequence(a.substr(0, size_a - 1), b),
                   lc_subsequence(a, b.substr(0, size_b - 1)));
}

int main() {
    string a, b;
    cin >> a >> b;
    
    cout << lc_subsequence(a, b) << endl;

    return 0;
}