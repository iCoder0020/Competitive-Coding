/*
ID: ishan-sang
PROG: Reverse Linked List
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
ListNode* Solution::reverseList(ListNode* A) 
{
    /*recursive
    if(A == NULL || A->next == NULL)
        return A;
    ListNode* p = reverseList(A->next);
    A->next->next = A;
    A->next = NULL;
    return p;*/

    /*iterative*/
    if(A == NULL)
        return A;
    ListNode *back, *curr, *fwd;
    curr = A;
    back = NULL;
    while(curr)
    {
        fwd = curr->next;
        curr->next = back;
        back = curr;
        curr = fwd;
    }
    return back;
}
