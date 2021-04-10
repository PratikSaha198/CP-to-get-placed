// To make a NEW LINKDELIST

// IN THE FIRST ONE YOU HAVE TO REVERSE A LINKEDLIST

// IN THE SECOND ONE YOU DONT HAVE TO DO SHIT


ListNode *head = NULL, *p = NULL;

while(root){
    p = new ListNode(root->val);
    p->next = head;
    head = p;
    root = root->next;
}

return head;

ListNode root(0);
ListNode *p = &root;

while (head)
{
    p->next = head;
    p = p->next;
    head = head->next;
}

return root.next;


// SORTING A LINKEDLIST IN O(1) space and O(nlogn) time

// Merge SORT is used
// Middle is 1st found
// Passed on revcursively of the left portion is the HEAD and MID to the right
// Merged the 2 positions


ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (!l1)
        return l2;
    else if (!l2)
        return l1;
    if (l1->val <= l2->val)
    {
        l1->next = merge(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}
ListNode *middle(ListNode *head)
{
    ListNode *midPrev = nullptr;
    while (head && head->next)
    {
        midPrev = (midPrev == nullptr) ? head : midPrev->next;
        head = head->next->next;
    }
    ListNode *mid = midPrev->next;
    midPrev->next = nullptr;
    return mid;
}
ListNode *sortList(ListNode *head)
{
    if (!head || !head->next)
        return head;
    ListNode *midi = middle(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(midi);
    return merge(left, right);
}