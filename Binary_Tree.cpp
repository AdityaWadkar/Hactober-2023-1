#include <iostream>

// Definition of a binary tree node
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary tree
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to perform an inorder traversal of the binary tree
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    TreeNode* root = nullptr;

    // Insert elements into the binary tree
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 4);

    // Perform an inorder traversal to print the sorted values
    std::cout << "Inorder Traversal (Sorted): ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}
