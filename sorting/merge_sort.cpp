#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int c = 0;
    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 and j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            c += mid - i;
        }
    }

    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return c;
}

int merge_sort(int arr[], int start, int end) {
    int c = 0;
    if (start < end) {
        int mid = (start + end) / 2;
        c += merge_sort(arr, start, mid);
        c += merge_sort(arr, mid + 1, end);
        c += merge(arr, start, mid, end);
    }

    return c;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    for (int n : arr) printf("%d ", n);
    printf("\n");

    int c = merge_sort(arr, 0, 6);

    for (int n : arr) printf("%d ", n);
    printf("\n");

    printf("%d\n", c);

    return 0;
}
