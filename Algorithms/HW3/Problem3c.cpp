// Alex Prior
// U54686687
// Collaborated with Allen Zou and Ib Chand, talked about general problem solving techniques and troubleshot errors together

#include "ListNode.h"

ListNode *findCycleStart(ListNode *head)
{
    ListNode *fast = head;     // Fast pointer
    ListNode *slow = head;     // Slow pointer
    while (fast && fast->next) // While fast pointer has a value and it points next to a value:
    {
        slow = slow->next;       // Iterate slow pointer
        fast = fast->next->next; // Iterate fast pointer (twice as fast as slow)
        if (fast == slow)        // If they are equal, break out of the while loop
            break;
    }
    if (fast == NULL || fast->next == NULL) // If fast does not have a value or it points to NULL:
        return NULL;                        // The linked list is not a cycle, return NULL
    else
    {
        slow = head;         // Set slow back to the beginning
        while (slow != fast) // While slow is not equal to fast:
        {
            slow = slow->next; // Iterate slow
            fast = fast->next; // Iterate fast (twice as fast)
        }
    }

    return fast; // Return the value of fast
}