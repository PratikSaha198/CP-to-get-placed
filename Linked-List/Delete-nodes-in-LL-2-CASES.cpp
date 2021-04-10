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


// Given the head of a linked list, remove the nth node from the end of the list and return its head.

int lengthll(ListNode *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}
ListNode *removeNthFromEnd(ListNode *bal, int n)
{

    // Find the total length and then find the index and then delete.
    // More time complexity

    int l = lengthll(bal);
    if(l==1) return NULL;
    int num = n;
    n = l-n-1;
    int cnt = 0;
    ListNode* head = bal;
    while(head and head->next){
        if(cnt==n) head->next = head->next->next;
        else head = head->next;
        cnt++;
    }
    if(l==num) return bal->next;
    return bal;

    // We could use two pointers
    // The first pointer advances the list by n+1n+1 steps from the beginning, while the second pointer starts from the beginning of the list
    // Now, both pointers are exactly separated by nn nodes apart. We maintain this constant gap by advancing both pointers together until the first pointer arrives past the last node
    // The second pointer will be pointing at the nnth node counting from the last
    // We relink the next pointer of the node referenced by the second pointer to point to the node's next next node.
    // O(1) space and Lesser time

    ListNode dum(0);
    dum.next = bal;
    ListNode *f = &dum, *s = &dum;
    for (int i = 0; i <= n; i++)
        s = s->next;
    while (s)
    {
        f = f->next;
        s = s->next;
    }
    f->next = f->next->next;
    return dum.next;
}