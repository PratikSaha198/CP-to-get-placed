// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices.
// And return the reordered list.

// The first node is considered odd, and the second node is even, and so on.

// Input: head = [1,2,3,4,5]
// Output: [1,3,5,2,4]

// EVERY LL has a node which has a head and a tail node.
// Make two seperate odd LL and a even LL
// Add the even's starting to the odd one's end

// [ head is the odd's head here ]

ListNode *oddEvenList(ListNode *head)
{
    if (!head)
        return head;

    ListNode *oddt = head;
    ListNode *evenh = head->next;
    ListNode *event = head->next;

    while (event && event->next)
    {
        oddt->next = oddt->next->next;
        event->next = event->next->next;
        oddt = oddt->next;
        event = event->next;
    }

    oddt->next = evenh;

    return head;
}