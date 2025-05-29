//mirror tree
// This code checks if a binary tree is symmetric (mirror image of itself).
// A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    bool Mirror(TreeNode* leftNode, TreeNode* rightNode){
        if(leftNode==nullptr && rightNode==nullptr) return true;
        if(leftNode==nullptr || rightNode==nullptr || leftNode->val != rightNode->val) return false;
        
        return Mirror(leftNode->left, rightNode->right) && Mirror(leftNode->right, rightNode->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return Mirror(root->left, root->right);
    }
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    if (isSymmetric(root)) {
        cout << "The tree is symmetric." << endl;
    } else {
        cout << "The tree is not symmetric." << endl;
    }

    return 0;
}