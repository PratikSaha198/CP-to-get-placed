// The Lisnked list is sorted in nature

// Make a copy of the head in curr
// Keep of going on till the 2nd last element (As the next to next pointer has its moving limit there)
// Check if same as previous, if so move the nxt of curr to next of next of curr
// Else normal move one forward.

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *curr = head;
    while (curr && curr->next)
    {
        if (curr->val == curr->next->val)
            curr->next = curr->next->next;
        else
            curr = curr->next;
    }
    return head;
}