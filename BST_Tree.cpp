/* A Binary Search Tree (or BST) is a data structure used in computer science for organizing 
 and storing data in a sorted manner. Each node in a Binary Search Tree has at most two 
 children, a left child and a right child, with the left child containing values less than 
 the parent node and the right child containing values greater than the parent node. 
 This hierarchical structure allows for efficient searching, insertion, and deletion operations
 on the data stored in the tree.
*/

//Insertion

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;    
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};

// A utility function to insert a new node with 
// the given key
Node* insert(Node* node, int key) {
  
    // If the tree is empty, return a new node
    if (node == NULL) 
        return new Node(key);    
    
    // If the key is already present in the tree,
    // return the node
    if (node->key == key) 
        return node;
    

    if (node->key < key) 
        node->right = insert(node->right, key);
    else 
        node->left = insert(node->left, key);
    
    // Return the (unchanged) node pointer
    return node;
}

// A utility function to do inorder tree traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}


int main() {

    Node* root = new Node(50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    return 0;
}

//Time Complexity: O(h) where h is the height of the tree.
//Space Complexity: O(n) where n is the number of nodes in the tree.
