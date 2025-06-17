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
Base case : the list is empty or has only one node
then the recursion stops

Tarpor newHead er moddhe next elements gular jnno recursive call 
In this case, front er moddhe next address store kora hoy
& front er next hoy old head(Mane ager element)
head-> next hoy null(last element gonna point to null)

newHead hbe reversed LL er head

*/
Node* Rec_Reverse(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* newHead = Rec_Reverse(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

// T.C O(n)
// S.C O(n) for recursion stack
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

    cout << "List : " << endl;
    printList(head);

    head = Rec_Reverse(head);
    cout << "List after Recursive Reverse: " << endl;
    printList(head);

    return 0;
}
