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

Node *instert_front(Node *head, int val)
{
    Node *temp = new Node(val, head);               //creates a new temp Node
    return temp;                                    //Returns the address of temp to assign it as new head (tail is fixed but head is updating here)
}

int main()
{
    int n, val;
    cout << "Enter the length of Linked List: " << endl;
    cin >> n;
    cout << "Enter " << n << " elements: ";
    cin >> val;
    Node *head = new Node(val);                       //Add first value manually
    for (int i = 2; i <= n; i++)                      // The rest values are to be added and linked in loop
    {
        cin >> val;
        head = instert_front(head, val);
    }
    cout << "List after using insert front (Stack-like) :" << endl;
    printList(head);

    return 0;
}
