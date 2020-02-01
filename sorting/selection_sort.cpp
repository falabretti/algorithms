#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int size) {
    int start_idx = 0;

    while (start_idx < size) {
        int smaller_idx = start_idx;

        for (int i = start_idx; i < size; i++){
            if (arr[i] < arr[smaller_idx]) {
                smaller_idx = i;
            }
        }

        swap(arr[start_idx], arr[smaller_idx]);
        start_idx++;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    selection_sort(arr, n);

    for (int i = 0; i < n; i++) cout << arr[i] << ' ';
    cout << endl;

    return 0;
}