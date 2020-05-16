#include <bits/stdc++.h>
using namespace std;

int bubble_sort(int arr[], int end) {
    int c = 0;
    if (end > 0) {
        for (int i = 0; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                c++;
            }
        }
        c += bubble_sort(arr, end - 1);
    }

    return c;
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    for (int n : arr) printf("%d ", n);
    printf("\n");

    int c = bubble_sort(arr, 6);

    for (int n : arr) printf("%d ", n);
    printf("\n");

    printf("%d\n", c);

    return 0;
}
