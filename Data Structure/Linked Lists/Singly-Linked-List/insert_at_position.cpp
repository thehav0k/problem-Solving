#include <iostream>
using namespace std;

struct Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* instert_at(Node *head, int val, int pos)
{
    if (pos == 1) {
        return new Node(val, head);
    }
    Node* temp = head;
    int count = 1;
    while (temp != nullptr && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == nullptr) {
        return head;
    }
    Node* newNode = new Node(val, temp->next);
    temp->next = newNode;
    return head;
}

int main()
{
    int n, val,pos;
    cout << "Enter the length of Linked List: " << endl;
    cin >> n;
    cout << "Enter the starting first element: ";
    cin >> val;
    Node *head = new Node(val);
    cout<<"Enter the value and the position in where to add :"<<endl;
    for (int i = 2; i <= n; i++)
    {
        cin >> val>>pos;
        head = instert_at(head, val,pos);
    }
    cout << "List after using inserting randomly :" << endl;
    printList(head);

    return 0;
}
