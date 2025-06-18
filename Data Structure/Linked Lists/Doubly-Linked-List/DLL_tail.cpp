// insert at tail and delete tail (queue)
// FIFO
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

// Insert at head (push for queue)
Node* push_front(Node* head, int val) {
    Node* temp = head;
    if (temp == nullptr) return new Node(val);
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// delete tail (pop for queue)
Node* pop_back(Node* head) {
    // Empty list
    if (head == nullptr) {
        return nullptr;
    }
    // Single node
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    // Traverse to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Update the second-to-last node's prev pointer
    temp->prev->next = nullptr;
    // Delete the last node
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
    Node* head = new Node(1);
    head = push_front(head, 2);
    head = push_front(head, 3);
    head = push_front(head, 4);
    print(head); // Output: 1 2 3 4
    head = pop_back(head);
    print(head); // Output: 1 2 3

    // clean memory
    deleteList(&head);
    print(head); // Output: Empty list

    return 0;
}