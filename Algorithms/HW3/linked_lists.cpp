#include <iostream>
#include "ListNode.h"

using namespace std;

int main()
{
    ListNode *head = new ListNode(10);

    ListNode *newVal;
    newVal = (ListNode *)malloc(sizeof(ListNode));
    newVal->val = 1;
    head->next = newVal;

    ListNode *newVal2;
    newVal2 = (ListNode *)malloc(sizeof(ListNode));
    newVal2->val = 8;
    head->next->next = newVal2;

    ListNode *temp = new ListNode(0);
    temp->next = head;

    cout << head->val << " -> " << head->next->val << " -> " << head->next->next->val << endl;

    int n = 1;

    while (temp->next != NULL)
    {
        if (temp->next->val == n && temp->next->next)
        {
            temp->next = temp->next->next;
        }
        else if (temp->next->val == n && temp->next->next == NULL)
        {
            temp->next = NULL;
        }
        else
        {
            temp = temp->next;
        }
    }

    cout << head->val << " -> " << head->next->val << endl;

    return 0;
}