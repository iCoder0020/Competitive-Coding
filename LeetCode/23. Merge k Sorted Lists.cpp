/*
ID: iCoder0020
PROG: Merge k Sorted Lists
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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<pair<int,ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>> pq;
        int K = lists.size();
        if(K == 0)
            return NULL;
        ListNode* t[K];
        for(int k = 0; k<K; k++)
        {
            t[k] = lists[k];
            if(t[k] != NULL)
                pq.push({t[k]->val, t[k]});
        }
        ListNode *head = new ListNode(0);
        ListNode *temp = head;
        ListNode *temp2;
        while(!pq.empty())
        {
            pair<int,ListNode*> v = pq.top();
            pq.pop();
            temp2 = new ListNode(v.first);
            temp->next = temp2;
            if(v.second->next)
            {
                v.second = v.second->next;
                pq.push({v.second->val, v.second});
            }
            temp = temp->next;
        }
        return head->next;  
    }
};