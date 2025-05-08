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

Node* instert_back(Node *head, int val)
{
    Node* temp = head;
    while(temp->next != nullptr){         //Checks if the next element is NULL
        temp = temp->next;                //Updates temp to next link in each iteration
    }
    Node* newNode = new Node(val);       //Creates a newNode
    temp->next = newNode;                //Links last temp to newNode
    return head;                         //Returns the updated head
}

int main()
{
    int n, val;
    cout << "Enter the length of Linked List: " << endl;
    cin >> n;
    cout << "Enter " << n << " elements: ";
    cin >> val;
    Node *head = new Node(val);
    for (int i = 2; i <= n; i++)
    {
        cin >> val;
        head = instert_back(head, val);
    }
    cout << "List after using insert back (Queue-like) :" << endl;   // similar to push into queue
    printList(head);

    return 0;
}
