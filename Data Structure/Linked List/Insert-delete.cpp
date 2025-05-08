#include <iostream>
#include<vector>
using namespace std;

struct Node {
public:
    int data;
    Node* next;
public: //Constructor to create a new Node with two parameters
    Node(int data1,Node* next1) {
        data=data1;
        next=next1;
    }
public: //Constructor to create a new Node with one parameter
    Node(int data1) {
        data=data1;
        next = nullptr;
    }
};

// Converting an array to a linked list
Node* Convert(vector<int>&arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for (int i=1;i<arr.size();i++) {
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

//Finding the length of a linked list
int Length_list(Node* head) {
    Node* temp=head;
    int count=0;
    while (temp) {
        count++;
        temp=temp->next;
    }
    return count;
}

//Linear searching on a linked list
bool search_list(Node* head,int target) {
    Node* temp=head;
    while (temp) {
       if (temp->data==target) return true;
        temp=temp->next;
    }
    return false;
}

//Printing elements of a linked list
void Print_list(Node* head) {
    Node* temp= head;
    while (temp) {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//Insert Value at head (As first-element)
Node* insertHead(Node* head,int val) {
    Node* temp =new Node(val,head);
    return temp;
}

//Insert Value at tail (As last element)
Node* insertTail(Node* head,int val) {
    Node* temp= head;
    while (temp->next!=nullptr) {
        temp=temp->next;
    }
    Node* newNode = new Node(val);
    temp->next=newNode;
    return head;
}

//Insert Value at k-th position (At any position including head and tail)
Node* insert_at_k(Node* head,int k,int val) {
    if (head==nullptr) {
        if (k==1) return new Node(val);
        else return head;
    }
    if (k==1) {
        Node* temp = new Node(val);
        return temp;
    }
    int count=0;
    Node* temp =head;
    while (temp!=nullptr) {
        count++;
        if (count==k-1) {
            Node* x= new Node(val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Insert a value before a target element.
//Find the position of an element and insert a value before it.
Node* insert_before_target(Node* head,int val,int target) {
    if (head==nullptr) {
        return head;
    }
    if (head->data==target) {
        Node* temp = new Node(val);
        return temp;
    }
    Node* temp =head;
    while (temp->next!=nullptr) {;
        if (temp->next->data==target) {
            Node* x= new Node(val,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

//Deleting value at head(first element)
Node* delete_head(Node* head) {
    if (head==nullptr)
        return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}
//Deleting value at tail(last element)
Node* delete_tail(Node* head) {
    if (head==nullptr || head->next==nullptr)
        return nullptr;
    Node* temp=head;
    while (temp->next->next!=nullptr) {
        temp= temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}
//Deleting value at k-th position
// Deleting value from any position including head and tail.
Node* delete_k(Node* head,int k) {
    if (head==nullptr)
        return head;
    if (k==1) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int count =0;
    Node* temp = head,*prev =nullptr;
    while (temp!=nullptr) {
        count++;
        if (count==k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp=temp->next;
    }
    return head;
}

//Deleting a value
//First-element that matches the value
Node* delete_value(Node* head,int val) {
    if (head==nullptr)
        return head;
    if (head->data==val) {
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp = head,*prev =nullptr;
    while (temp!=nullptr) {
        if (temp->data==val) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp=temp->next;
    }
    return head;
}
int main() {
    vector<int> arr ={2,3,5,4};
    Node* head= Convert(arr);

    cout<<"Initial list:"<<endl;
    Print_list(head);

    cout<<"Length of list: "<<Length_list(head)<<endl;

    cout<<"Does 6 exist in the list? -"<<(search_list(head,6)? "YES" : "NO")<<endl;
    cout<<"Does 4 exist in the list? -"<<(search_list(head,4)? "YES" : "NO")<<endl;

    cout<<"After adding 33 in the head of the list :"<<endl;
    head= insertHead(head,33);
    Print_list(head);

    cout<<"After adding 69 in the tail of the list :"<<endl;
    head= insertTail(head,69);
    Print_list(head);

    cout<<"After adding 50 in the 4th position of the list :"<<endl;
    head= insert_at_k(head,4,50);
    Print_list(head);

    cout<<"After adding 18 before 3 in the list :"<<endl;
    head= insert_before_target(head,18,3);
    Print_list(head);

    head = delete_head(head);
    cout<<endl<<"List after deleting head(first element):"<<endl;
    Print_list(head);

    head = delete_tail(head);
    cout<<endl<<"List after deleting tail(last element):"<<endl;
    Print_list(head);

    cout<<endl<<"After deleting 2nd element, the list is: "<<endl;
    head= delete_k(head,2);
    Print_list(head);

    cout<<endl<<"After deleting an element valued 50 , the list is: "<<endl;
    head= delete_value(head,50);
    Print_list(head);


    return 0;
}
