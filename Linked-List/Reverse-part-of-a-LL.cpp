// Given the head of a singly linked list and two integers left and right where left <= right.
// Reverse the nodes of the list from position left to position right, and return the reversed list.


// Create a new LL
// Bring a pointer 'prev' to the element just before the starting index of reversing
// Name a pivot element to be the first element the reversing
// Keep on adding elements after pivot to just after the prev element
// Repeat the process


ListNode *reverseBetween(ListNode *head, int left, int right)
{
    ListNode dum(0), *prev = &dum;
    dum.next = head;

    for (int i = 1; i < left; i++)
        prev = prev->next;
    
    ListNode *pivot = prev->next;
    
    for (int i = left; i < right; i++)
    {   
        // WAY 1 ---->
        swap(prev->next, pivot->next->next);
        swap(prev->next, pivot->next);

        // WAY 2 ---->
        ListNode *bal = pivot->next;
        pivot->next = bal->next;
        bal->next = prev->next;
        prev->next = bal;

        // WAY 3 ---->
        ListNode *tmp = pivot->next;
        pivot->next = pivot->next->next;
        tmp->next = prev->next;
        prev->next = tmp;
    }
    return dum.next;
}