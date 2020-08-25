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

Node* find_max(Node* root) {

    Node* cur = root;

    while (cur->right != NULL)
        cur = cur->right;

    return cur;
}

Node* remove(Node* root, int data) {

    if (root == NULL)
        return root;
    
    if (data < root->data) {
        root->left = remove(root->left, data);
    } else if (data > root->data) {
        root->right = remove(root->right, data);
    } else {

        if (root->left == NULL or root->right == NULL) {
            Node* new_root = root->left ? root->left : root->right;
            delete root;
            return new_root;
        }

        Node* temp = find_max(root->left);
        root->data = temp->data;
        root->left = remove(root->left, root->data);
    }

    return root;
}

Node* search(Node* root, int data, vector<int>& path) {
    
    if (root == NULL or root->data == data)
        return root;

    path.push_back(root->data);
    
    if (data < root->data) {
        return search(root->left, data, path);
    } else {
        return search(root->right, data, path);
    }
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int values[] = { 12, 5, 15, 3, 7, 13, 17, 1, 9, 14, 20, 8, 11, 18 };
    int n = sizeof(values) / sizeof(int);

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = add(root, values[i]);
    }

    vector<int> path;
    Node* node = search(root, 13, path);

    return 0;
}
