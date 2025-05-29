// 3 Tree Traversals


//Inorder Traversal
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;    
    Node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    void printInorder(struct Node* node){
    if (node == nullptr)
        return;

    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
//Tiem Complexity: O(n)
//Space Complexity: O(h) where h is the height of the tree

    //PREORDER TRAVERSAL

    void printPreorder(struct Node* node){
        if (node == nullptr)
            return;

        cout << node->data << " ";
        printPreorder(node->left);
        printPreorder(node->right);
    }
    //time Complexity: O(n)
//Space Complexity: O(h) where h is the height of the tree


    //POST ORDER TRAVERSAL

    void printPostorder(struct Node* node){
        if (node == nullptr)
            return;

        printPostorder(node->left);
        printPostorder(node->right);
        cout << node->data << " ";
    }
    };
//Time Complexity: O(n) 
    
 int main() {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);

        cout << "Inorder traversal: ";
        root->printInorder(root);
        cout << endl;

        cout << "Preorder traversal: ";
        root->printPreorder(root);
        cout << endl;

        cout << "Postorder traversal: ";
        root->printPostorder(root);
        cout << endl;

        return 0;
    }
