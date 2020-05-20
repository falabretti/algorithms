#include <bits/stdc++.h>
using namespace std;

void bucket_sort(double arr[], int n) {
    vector<double> buckets[n];

    for (int i = 0; i < n; i++) {
        int idx = arr[i] * 10;
        buckets[idx].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) sort(buckets[i].begin(), buckets[i].end());

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[k++] = buckets[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double arr[] = {.78, .17, .39, .26, .72, .94, .21, .12, .23, .68};

    for (double n : arr) printf("%lf ", n);
    printf("\n");

    bucket_sort(arr, 10);

    for (double n : arr) printf("%lf ", n);
    printf("\n");

    return 0;
}
