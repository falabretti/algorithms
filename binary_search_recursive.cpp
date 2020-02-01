#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int target) {
    if (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] < target)
            return binary_search(arr, mid + 1, end, target);
        else if (arr[mid] > target)
            return binary_search(arr, start, mid - 1, target);
        else
            return mid;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    int t;
    cin >> t;

    cout << binary_search(arr, 0, n - 1, t) << endl;

    return 0;
}