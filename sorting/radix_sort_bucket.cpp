#include <bits/stdc++.h>
using namespace std;

void radix_bucket_sort(int arr[], int n, int digit) {
    vector<int> buckets[n];

    for (int i = 0; i < n; i++) {
        int idx = (arr[i] / digit) % 10;
        buckets[idx].push_back(arr[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

void radix_sort(int arr[], int n) {
    int ceil = *max_element(arr, arr + n);

    for (int digit = 1; ceil / digit > 0; digit *= 10) {
        radix_bucket_sort(arr, n, digit);
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
