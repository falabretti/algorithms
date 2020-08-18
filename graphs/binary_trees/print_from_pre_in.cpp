#include <bits/stdc++.h>

using namespace std;

int pre_idx = 0;
unordered_map<int, int> in_ref;

void print_tree(int pre_order[], int start, int end) {

    if (start > end)
        return;

    int data = pre_order[pre_idx++];
    int root = in_ref[data];

    // post_order
    print_tree(pre_order, start, root - 1);
    print_tree(pre_order, root + 1, end);
    cout << data;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const int SIZE = 6;
    int pre_order[] = { 1, 2, 4, 5, 3, 6 }; 
    int in_order[] = { 4, 2, 5, 1, 3, 6 }; 

    pre_idx = 0;
    in_ref.clear();

    for (int i = 0; i < SIZE; i++)
        in_ref[in_order[i]] = i;

    print_tree(pre_order, 0, SIZE - 1);
    cout << endl;
    
    return 0;
}
