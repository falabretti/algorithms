#include <bits/stdc++.h>
using namespace std;

void radix_counting_sort(int arr[], int n, int digit) {
    int count[10];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++) count[(arr[i] / digit) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];

    int copy[n];
    for (int i = n - 1; i >= 0; i--) {
        int idx = (arr[i] / digit) % 10;
        copy[count[idx]-- - 1] = arr[i];
    }

    for (int i = 0; i < n; i++) arr[i] = copy[i];
}

void radix_sort(int arr[], int n) {
    int ceil = *max_element(arr, arr + n);

    for (int digit = 1; ceil / digit > 0; digit *= 10) {
        radix_counting_sort(arr, n, digit);
    }
}

int main() {
    int arr[] = {38, 27, 43, 41, 47, 45, 3, 9, 82, 10};

    for (int n : arr) printf("%d ", n);
    printf("\n");

    radix_sort(arr, 10);

    for (int n : arr) printf("%d ", n);
    printf("\n");

    return 0;
}
