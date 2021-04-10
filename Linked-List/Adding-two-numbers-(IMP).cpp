// You are given two non - empty linked lists representing two non - negative integers.The most significant digit comes first and each of their nodes contain a single digit.Add the two numbers and return it as a linked list.

// Input : (7->2->4->3) + (5->6->4)
// Output : 7->8->0->7

// Take in both the numbers as input.
// Move from back to front, and add the numbers in sum and the carry is the number/10
// THE CONCEPT OF CREATING NEW LINKED LIST IS USED.     
// Add the last digit to the node and make the sum the carry for the next iteration of the loop


ListNode* addTwoNumbers(ListNode * l1, ListNode *l2)
{
    vector<int> one, two;
    while (l1)
    {
        one.push_back(l1->val);
        l1 = l1->next;
    }
    while (l2)
    {
        two.push_back(l2->val);
        l2 = l2->next;
    }

    int sum = 0, carry = 0;
    ListNode *head = NULL, *p = NULL;

    for (int i = one.size() - 1, j = two.size() - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
    {
        sum = carry;
        if (i >= 0)
            sum += one[i];
        if (j >= 0)
            sum += two[j];
        carry = sum / 10;
        p = new ListNode(sum % 10);
        p->next = head;
        head = p;
    }

    return head;
}