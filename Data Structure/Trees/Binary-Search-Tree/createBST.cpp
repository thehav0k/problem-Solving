#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

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
    
    cout << "Binary Search Tree Created with root value: " << root->data << endl;

    return 0;
}