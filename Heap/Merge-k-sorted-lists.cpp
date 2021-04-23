// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation:
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Use a min heap to always store the least element in the top and keep on traversing by inserting the next node


// One way of COMPARATOR FUNCTION --------------------------->

// struct compare{
//     bool operator()(const ListNode* l, const ListNode* r)
//     {
//         return l->val > r->val;
//     }
// };

// ---------------------------------------------------------->

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    // priority_queue<ListNode *, vector<ListNode *>, compare> pq; // IMPORTANT COMPARATOR FUNCTION (ABOVE COMP used)
 
    auto comp = [&](const ListNode* l, const ListNode* r){
            return l->val > r->val;
    };
    
    // Max heap according to first value of a LL
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> pq(comp);

    for(auto it : lists){
        if(it) pq.push(it);
    }

    if(pq.empty())
        return NULL;
    
    // Take in the highest valued node
    ListNode* result = pq.top();
    pq.pop();
    
    // Add into the queue the next element into that list if it exists
    if(result->next)
        pq.push(result->next);
    
    // Make a pointer to the result which will move
    ListNode* tail = result;

    // Keep on adding and moving    
    while(!pq.empty())
    {
        tail->next = pq.top();
        pq.pop();
        
        tail = tail->next;
        
        if(tail->next) 
            pq.push(tail->next);
    }

    return result;
}