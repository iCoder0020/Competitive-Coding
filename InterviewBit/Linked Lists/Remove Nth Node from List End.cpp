/*
ID: ishan-sang
PROG: Remove Nth Node from List End
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
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) 
{
    int N = 0;
    ListNode *temp = A;
    while(temp)
    {
        N++;
        temp = temp->next;
    }
    if(N<=B)
    {
        A = A->next;
        return A;
    }
    temp = A;
    for(int n = 0; n<N-B-1; n++)
        temp = temp->next;
    if(temp->next)
        temp->next = temp->next->next;
    else
        temp = NULL;
    return A;
}
