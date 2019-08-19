/*
ID: ishan-sang
PROG: Reorder List
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
ListNode* reverseLL(ListNode *head)
{
    if(!head || !head->next)
        return head;
    ListNode* p = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}
ListNode* Solution::reorderList(ListNode* A) 
{
    if(!A || !A->next || !A->next->next)
        return A;
    int N = 0;
    ListNode *temp, *f, *l, *fnext, *lnext;
    temp = A;
    while(temp)
    {
        N++;
        temp = temp->next;
    }
    temp = A;
    for(int i = 0; i<(N+1)/2-1; i++)
        temp = temp->next;
    l = reverseLL(temp);
    f = A;
    temp = A;
    f = f->next;
    for(int i = 0; i<N-((N+1)%2); i++)
    {
        if(i%2 == 0)
        {
            lnext = l->next;
            temp->next = l;
            l = lnext;
        }
        else
        {
            fnext = f->next;
            temp->next = f;
            f = fnext;
        }
        temp = temp->next;
    }
    temp->next = NULL;
    return A;
}
