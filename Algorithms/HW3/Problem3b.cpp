// Alex Prior
// U54686687
// Sources: https://stackoverflow.com/questions/7262078/how-do-you-move-between-nodes-of-a-linked-list

#include "ListNode.h"

ListNode *insertionSortList(ListNode *head)
{
    ListNode *placeholder = new ListNode(0); // Empty node
    placeholder->next = head;                // Placeholder to retain beginning of list
    ListNode *temp = new ListNode(0);        // Empty node
    temp->next = placeholder;                // To be used for iterating from the beginning of the linked list

    ListNode *currentPointer = head; // Set iterating pointer to beginning of linked list
    ListNode *insertionPoint;
    while (currentPointer->next != NULL) // While we have not reached the end of the linked list:
    {
        if (currentPointer->val >= currentPointer->next->val) // If the first node is greater than or equal to the value in the node ahead of currentPointer:
        {
            currentPointer = currentPointer->next; // This node is already sorted and can be iterated to the next node
        }
        else // Else the node is not sorted and we need to find where to put it
        {
            temp->next = head;
            insertionPoint = currentPointer->next;
            if (insertionPoint->next)
                currentPointer->next = insertionPoint->next;
            else
                currentPointer->next = NULL;
            while (insertionPoint < temp->next) // While the value ahead of currentPointer is less than the value ahead of temp:
                temp = temp->next;              // Iterate temp to find when it is less than the value ahead of currentPointer
            temp->next = insertionPoint;
            insertionPoint->next = currentPointer;
        }
        head = placeholder->next;
    }
    delete temp;

    return placeholder->next;
}