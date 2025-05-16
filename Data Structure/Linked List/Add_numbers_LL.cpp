#include <iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }
};

class Solution
{
public:
    // duita linked list e duita number ache reverse order e
    // tader sum kora lagbe
    // jemon 2->4->6 + 3->8->7 = 5->2->4->1
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *t1 = l1; // l1 er head temporary variable 1 e
        ListNode *t2 = l2; // l2 er head temporary variable 2 e
        // DummyNode er maddhome linked list er shuru te ekta dummy node banabo
        // jate linked list er shuru te kono node na thakle o jhamela na hoy
        ListNode *DummyNode = new ListNode(-1);
        ListNode *curr = DummyNode; // curr er maddhome linked list e notun node add korbo
        int carry = 0;              // carry er maddhome 10 er beshi hole carry ta nibo
        while (t1 || t2)
        { // t1 and t2 er shuru theke shesh porjonto jabe
            // sum ke carry er shathe add korbo
            int sum = carry;
            // t1 and t2 er maddhome linked list er node gulo ke check korbo
            // jodi t1 and t2 er node thake tahole tader value ta sum e add korbo
            if (t1)
                sum += t1->val;
            if (t2)
                sum += t2->val;
            // sum er moddhe 10 er beshi hole carry ta nibo
            // example hisebe 4+8 = 12 hole newNode er moddhe 2 thakbe
            // ar carry er moddhe 1 thakbe
            ListNode *newNode = new ListNode(sum % 10);
            carry = sum / 10;

            // curr er next newNode ke point korbe
            curr->next = newNode;
            // curr ke samner dike dike nibo
            // like i++
            curr = curr->next;
            // t1 and t2 ke next e niye jabo
            // like t1++ and t2++
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        // jodi loop shesheo carry thake tahole newNode er moddhe carry ta nibo
        if (carry)
        {
            ListNode *newNode = new ListNode(carry);
            curr->next = newNode;
        }
        // DummyNode er next ta return korbo head hisebe
        // karon DummyNode er moddhe -1 thakbe
        // jeta amra chaitesi na
        return DummyNode->next;
    }
};

int main()
{
    Solution sol;
    // 2 4 6 digits diye l1 banabo... Asol number 642
    ListNode *l1 = new ListNode(2, new ListNode(4, new ListNode(6)));
    // 3 8 7 digits diye l2 banabo... Asol number 738
    ListNode *l2 = new ListNode(3, new ListNode(8, new ListNode(7)));
    // l1 and l2 er sum hobe 5 2 4 1... Asol number 1245
    ListNode *res = sol.addTwoNumbers(l1, l2);
    // result print korbo... Single for loop diye
    // t = res er shuru theke shesh porjonto jabe
    // t->next er shathe t->val print korbo
    for (ListNode *t = res; t; t = t->next)
        cout << t->val << (t->next ? "->" : "");
    cout << endl;
    return 0;
}
