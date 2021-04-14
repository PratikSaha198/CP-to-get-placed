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


// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
// k is a positive integer and is less than or equal to the length of the linked list. 
// If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Function to reverse from a starting node to a end node is made. It returns the starting of the list
// For every next k elements recursively keep on revsersing by passing the newhead (after k elements) and keep on returning it.


ListNode* reverse(ListNode* f, ListNode* l)
{
    ListNode* curr=f;
    ListNode *prev=NULL, *nex=NULL;

    while(curr!=l){
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    f = prev;

    return f;
}
ListNode* reverseKGroup(ListNode* head, int k)
{
    auto last = head;

    for(int i=0;i<k;i++){
        if(!last) return head;
        last = last->next;
    }

    auto newhead = reverse(head, last);
    head->next = reverseKGroup(last, k);
    
    return newhead;
}