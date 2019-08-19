/*
ID: ishan-sang
PROG: Reverse Link List Recursion
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
ListNode* Solution::reverseList(ListNode* A) {
    if(!A || !A->next)
        return A;
    ListNode *p = reverseList(A->next);
    A->next->next = A;
    A->next = NULL;
    return p;
}
