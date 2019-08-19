/*
ID: ishan-sang
PROG: Swap List Nodes in pairs
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
ListNode* Solution::swapPairs(ListNode* A) 
{
    if(!A || !A->next)
        return A;
    ListNode *curr, *t1, *t2;
    curr = A;
    A = A->next;
    while(1)
    {
        t2 = curr;
        curr = curr->next;
        t1 = curr->next;
        curr->next = t2;
        if(t1 && t1->next)
            t2->next = t1->next;
        else
        {
            t2->next = t1;
            break;
        }
        curr = t1;
    }
    return A;
}
