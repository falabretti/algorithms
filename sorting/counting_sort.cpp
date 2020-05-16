#include <bits/stdc++.h>
using namespace std;

void counting_sort(int arr[], int n, int max) {
    int count[max + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) count[arr[i]]++;

    for (int i = 0, k = 0; i <= max; i++) {
        while (count[i] > 0) {
            arr[k++] = i;
            count[i]--;
        }
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    counting_sort(arr, 7, 100);

    for (int n : arr) printf("%d ", n);
    printf("\n");

    return 0;
}
