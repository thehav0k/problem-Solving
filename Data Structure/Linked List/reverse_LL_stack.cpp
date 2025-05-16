#include <iostream>
#include <stack>
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

/*So technicaally first ekta stack er maddhome linked list
 er data gulo ke push kore nibo...stack er top() e sobsomoy
 last element thake..Alada arekta loop diye Linkedlist e stack top() er
 moddhe store kora value gulo assign korlei Linkedlist reverse hoye jbe
 stack er top use korar por protibar pop kore nite hbe*/

Node *Reverse_with_stack(Node *head)
{
    Node *temp = head;
    stack<int> st;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;// temp abar head e niye aslam jate linked list er shuru te jawa jay
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

//T.C = O(2n)
//S.C = O(n)

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
    cout << "Normal List: " << endl;
    printList(head);

    //head = Reverse(head);
    head = Reverse_with_stack(head);
    cout << "List after reversing with stack: " << endl;
    printList(head);

    return 0;
}

//In this way, the LL is reversed using stack where the data is reversed
// and the address is not changed. So, the address of the head is not changed.
