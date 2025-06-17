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

// Insert at head (push for stack)
Node* push_back(Node* head, int val) {
    Node* temp = new Node(val);
    if (head != nullptr) {
        temp->next = head;
        head->prev = temp;
    }
    return temp;
}

// Delete head (pop for stack)
Node* pop_front(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    Node* temp = head->next;
    delete head; // Free the head node
    if (temp != nullptr) {
        temp->prev = nullptr; // Only set prev if temp is not nullptr
    }
    return temp;
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
    head = push_back(head, 2);
    head = push_back(head, 3);
    head = push_back(head, 4);
    print(head); // Output: 4 3 2 1
    head = pop_front(head);
    print(head); // Output: 3 2 1

    // clean memory
    deleteList(&head);
    print(head); // Output: Empty list

    return 0;
}