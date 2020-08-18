#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {

    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

int pre_idx;
unordered_map<int, int> in_ref;

Node* build_sub_tree(int pre_order[], int start, int end) {
    
    if (start > end)
        return NULL;

    int data = pre_order[pre_idx++];
    Node* node = create_node(data);

    if (start == end)
        return node;

    int root = in_ref[data];

    node->left = build_sub_tree(pre_order, start, root - 1);
    node->right = build_sub_tree(pre_order, root + 1, end);

    return node;
}

Node* build_tree(int pre_order[], int in_order[], int size) {

    pre_idx = 0;
    in_ref.clear();

    for (int i = 0; i < size; i++)
        in_ref[in_order[i]] = i;
    
    return build_sub_tree(pre_order, 0, size - 1);
}

void print_tree(Node* root) {

    if (root == NULL)
        return;

    // post_order
    print_tree(root->left);
    print_tree(root->right);
    cout << root->data << " ";
}

int main() {

    const int SIZE = 6;
    int pre_order[] = { 1, 2, 4, 5, 3, 6 };
    int in_order[] = { 4, 2, 5, 1, 6, 3 };

    Node* root = build_tree(pre_order, in_order, SIZE);

    print_tree(root);
    cout << endl;

    return 0;
}
