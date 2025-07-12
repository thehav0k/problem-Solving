#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
//Recursive function to search for a key in the BST
//Returns the node containing the key if found, otherwise returns nullptr
Node* searchInBST(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return searchInBST(root->left, key);  
    } else {
        return searchInBST(root->right, key); 
    }  
}

//iterative function to search for a key in the BST
//Returns the node containing the key if found, otherwise returns nullptr
Node* searchInBSTIterative(Node* root, int key) {
    while (root != nullptr && root->data != key) {
        if (key < root->data) {
            root = root->left;  
        } else {
            root = root->right; 
        }
    }
    return root;  // returns nullptr if key is not found      
}
int main() {
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->right = new Node(20);

    // Tree structure:
    //             10
    //        5          15
    //     3     7          20
    
    int key = 7;
    Node* result = searchInBST(root, key);
    
    if (result != nullptr) {
        cout << "Key " << key << " found in BST." << endl;
    } else {
        cout << "Key " << key << " not found in BST." << endl;
    }
    
    key = 25;
    Node* resultIterative = searchInBSTIterative(root, key);
    if (resultIterative != nullptr) {
        cout << "Key " << key << " found in BST using iterative method." << endl;
    } else {
        cout << "Key " << key << " not found in BST using iterative method." << endl;
    }

    return 0;
}