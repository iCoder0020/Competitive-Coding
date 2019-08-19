/*
ID: ishan-sang
PROG: Merge K Sorted Lists
LANG: C++                  
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeKLists(vector<ListNode*> &A) 
{
    int N = A.size();
    ListNode *C_head = NULL, *C, *temp;
    priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> PQ;
    for(int n = 0; n<N; n++)
        PQ.push({A[n]->val, A[n]});
    while(!PQ.empty())
    {
        int v = PQ.top().first;
        ListNode* node = PQ.top().second;
        PQ.pop();
        temp = new ListNode(v);
        if(!C_head)
        {
            C_head = temp;
            C = C_head;
        }
        else
        {
            C->next = temp;
            C = C->next;
        }
        if(node->next == NULL)
            continue;
        node = node->next;
        PQ.push({node->val, node});
    }
    return C_head;   
}
