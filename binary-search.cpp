#include <iostream>
#include <vector>
using namespace std;

//Define the node as a struct
struct node {
    int val;
    node* left;
    node* right;
    node(int x) : val(x), left(nullptr), right(nullptr) {}
};

//Recursive insert function
node* insert(node* root, int key) {
    if (!root) return new node(key); //for root = null.
    if (key < root->val) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

//Preorder traversal of the BST
void preorder(node* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    // Read the input sequence
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Construct the BST
    node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = insert(root, a[i]);
    }

    // Output the preorder traversal
    preorder(root);
    cout << endl;

    return 0;
}
