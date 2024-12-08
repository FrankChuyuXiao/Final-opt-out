#include <iostream>
#include <algorithm>
using namespace std;

//Define the node as a struct
struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

//Recursive function for inserting a key into BST tree
node* insert(node* root, int key) {
    if (root == nullptr) return new node(key); //for root = null.
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

//Preorder traversal
void preorder(node* root) {
    if (!root)
        return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x[n];
    node* root = nullptr;

    // Read the input sequence
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 0; i < n; ++i) {
       root = insert(root, x[i]);
    }
    // Output the preorder traversal
    preorder(root);
    cout << endl;

    return 0;
}
