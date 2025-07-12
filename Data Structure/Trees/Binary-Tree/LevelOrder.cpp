#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<vector<int>> LevelOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<Node*> q;  // ekta queue te Node address rakha hobe
    q.push(root);

    while(!q.empty()) {
        int size = q.size();  //level e koto gulo node ache ta ber korbo 
        vector<int> level;
        for(int i = 0; i < size; i++) {
            Node* node = q.front(); // queue theke front node ta ber korbo
            q.pop(); // queue theke node ta remove korbo
            level.push_back(node->data);  // node er data ta level vector e add korbo
            if(node->left) q.push(node->left); //jodi left child thake tahole queue te add korbo
            if(node->right) q.push(node->right); //jodi right child thake tahole queue te add korbo
        }
        result.push_back(level); // level vector ta result vector e add korbo
    }
    return result;

}

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

    vector<vector<int>> vec = LevelOrder(root);
    cout << "Level Order Traversal:\n";
    for (const auto& row : vec) { // iterate through each level -> row
        for (int el : row) { // in each level or row , print elements from left
            cout << el << " ";
        }
    }
    cout << endl;
    
    return 0;
}