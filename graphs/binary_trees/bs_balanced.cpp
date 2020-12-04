#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node (int d) :
        data(d),
        left(NULL),
        right(NULL) { }
} Node;

Node* add(Node* root, int data) {

    if (root == NULL) 
        return new Node(data);

    if (data < root->data)
        root->left = add(root->left, data);
    else 
        root->right = add(root->right, data);
    
    return root;
}

void pre_order(Node* root) {

    if (root == NULL)
        return;

    cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node* root) {

    if (root == NULL)
        return;

    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

void post_order(Node* root) {

    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->data << " ";
}

Node* build_balanced(int values[], int start, int end) {

    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(values[mid]);

    root->left = build_balanced(values, start, mid - 1);
    root->right = build_balanced(values, mid + 1, end);

    return root;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int values[] = { 108, 55, 34, 77, 20, 10, 7, 6, 4, 3, 2, 1 };
    int n = sizeof(values) / sizeof(int);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = add(root, values[i]);
    }

    pre_order(root);
    cout << "\n";

    sort(values, values + n);

    Node* balanced_root = build_balanced(values, 0, n - 1);
    pre_order(balanced_root);

    return 0;
}
