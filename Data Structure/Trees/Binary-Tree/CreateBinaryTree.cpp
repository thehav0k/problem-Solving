
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->left->right->left = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    // Tree structure:
    //             1
    //        2          3
    //     4     5    7     8
    //         6          9   10
    
    cout << "Binary Tree Created with root value: " << root->data << endl;
    
    
    return 0;
}
