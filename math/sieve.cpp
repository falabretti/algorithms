#include <bits/stdc++.h>
using namespace std;

void sieve(int n) {
    bool primes[n + 1];
    memset(primes, true, sizeof(primes));

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (primes[i]) printf("%d\n", i);
    }
}

int main() {

    sieve(100000);

    return 0;
}
