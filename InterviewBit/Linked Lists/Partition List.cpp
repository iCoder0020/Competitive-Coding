/*
ID: ishan-sang
PROG: Partition List
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
ListNode* Solution::partition(ListNode* A, int B) 
{
    if(!A || !A->next)
        return A;
    ListNode *t1 = NULL, *t2 = NULL, *curr = A, *prev = NULL;
    while(curr && curr->val >= B)
    {
        prev = curr;
        curr = curr->next;
    }
    t1 = curr;
    if(!t1)
        return A;
    if(t1 != A)
    {
        prev->next = t1->next;
        t1->next = A;
        A = t1;
    }
    curr = t1->next;
    while(curr && curr->val < B)
    {
        prev = curr;
        curr = curr->next;
    }
    t2 = curr;
    if(!t2)
        return A;
    curr = t2->next;
    prev = t2;
    while(curr)
    {
        if(curr->val < B)
        {
            prev->next = curr->next;
            curr->next = t2;
            t1->next = curr;
            t1 = curr;
            
            curr = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
        
    }
    return A;
}
