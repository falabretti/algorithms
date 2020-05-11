#include <bits/stdc++.h>
using namespace std;

// 1 based
int josephus(int n, int k) {
    if (n == 1) return 1;
    return (josephus(n - 1, k) + k - 1) % n + 1;
}

// 0 based
int josephus2(int n, int k) {
    if (n == 1) return 0;
    return (josephus2(n - 1, k) + k) % n;
}

// 1 based loop
int josephus3(int n, int k) {
    int res = 0;
    for (int i = 2; i <= n; i++) res = (res + k) % i;
    return res + 1;
}

int main() {
    cout << josephus(2, 3) << endl;
    cout << josephus(3, 3) << endl;
    cout << josephus(4, 3) << endl;
    cout << josephus(5, 3) << endl;
    cout << josephus(6, 3) << endl;
    cout << josephus(7, 3) << endl;

    return 0;
}
