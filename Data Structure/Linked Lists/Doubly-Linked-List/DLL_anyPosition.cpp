// insert at random position and delete k-th number
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    explicit Node(const int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

// Print the list
void print(Node* head) {
    if (head == nullptr) {
        cout << "Empty list" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* push_at(Node* head, int val, int k) {
    // Invalid position
    if (k <= 0) {
        cout << "Invalid position: k must be positive" << endl;
        return head;
    }
    // Empty list
    if (head == nullptr) {
        if (k == 1) {
            return new Node(val);
        } else {
            cout << "Invalid position: list is empty, k must be 1" << endl;
            return nullptr;
        }
    }
    // Insert at head (k == 1)
    if (k == 1) {
        Node* new_node = new Node(val);
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    // Traverse to (k-1)-th node
    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < k - 1) {
        temp = temp->next;
        count++;
    }
    // If k is beyond list length
    if (temp == nullptr) {
        cout << "Invalid position: k exceeds list length" << endl;
        return head;
    }
    // Insert new node
    Node* new_node = new Node(val);
    new_node->next = temp->next;
    new_node->prev = temp;
    temp->next = new_node;
    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
    return head;
}

Node* pop_at(Node* head, int pos) {
    // Invalid position
    if (pos <= 0) {
        cout << "Invalid position: pos must be positive" << endl;
        return head;
    }
    // Empty list
    if (head == nullptr) {
        cout << "Invalid position: list is empty" << endl;
        return nullptr;
    }
    // Delete head (pos == 1)
    if (pos == 1) {
        Node* temp = head->next;
        delete head;
        if (temp != nullptr){
            temp->prev = nullptr;
        }
        return temp;
    }
    // Traverse to pos-th node
    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < pos) {
        temp = temp->next;
        count++;
    }
    // If pos exceeds list length
    if (temp == nullptr) {
        cout << "Invalid position: pos exceeds list length" << endl;
        return head;
    }
    // Update pointers and delete node
    temp->prev->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    delete temp;
    return head;
}

// sob kaj sheshe memory free kora
void deleteList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    *head = nullptr;
}

int main() {
    Node* head = new Node(1); // 1
    head = push_at(head, 2,1); // 2 1
    head = push_at(head, 3,2); // 2 3 1
    head = push_at(head, 4,2); // 2 4 3 1
    print(head); // Output: 2 4 3 1
    head = pop_at(head,2);
    print(head); // Output: 2 3 1

    // clean memory
    deleteList(&head);
    print(head); // Output: Empty list

    return 0;
}