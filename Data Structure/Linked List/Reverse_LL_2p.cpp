#include <iostream>
using namespace std;

class Node
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

Node *insert(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

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

/*
first e ekta temp = head nibo
then previous node and front node track rakhar jnno aro duita null node nibo
new front hobe temp er next mane current node er next
basically front node diye just next node gulo temporary store kora hocche
karon temp->next proti iteration e change hocche
tarpor temp->next point korbe previous node ke (ulta dike link hocche)
ekhn new previous hobe current temp and new temp hbe front(also we can say temp->next)
evabe prev hoye jbe LL er new head and etai return korbe func
*/
Node *Reverse(Node *head)
{
    Node *temp = head, *prev = nullptr;
    Node *front = nullptr;
    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}
// T.C : O(n)
// S.C : O(1)

int main()
{
    int n;
    cout << "Enter the length of Linked List: " << endl;
    cin >> n;
    cout << "Enter " << n << " elements: ";
    int val;
    cin >> val;
    Node *head = new Node(val);
    for (int i = 2; i <= n; i++)
    {
        cin >> val;
        head = insert(head, val);
    }

    cout << "List 1: " << endl;
    printList(head);

    head = Reverse(head);
    cout << "List 1 after Reverse: " << endl;
    printList(head);

    return 0;
}
