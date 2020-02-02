#include <bits/stdc++.h>
using namespace std;

int moves = 0;

void hanoi_tower(int n, char begin, char end, char aux) {
    if (n == 1) {
        printf("%c -> %c\n", begin, end);
        moves++;
    } else {
        hanoi_tower(n - 1, begin, aux, end);
        hanoi_tower(1, begin, end, aux);
        hanoi_tower(n - 1, aux, end, begin);
    }
}

int main() {
    int n;
    cin >> n;

    // minimum moves = 2^n - 1

    hanoi_tower(n, 'A', 'C', 'B');
    printf("Total moves: %d\n", moves);

    return 0;
}
