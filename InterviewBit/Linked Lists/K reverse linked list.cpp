/*
ID: ishan-sang
PROG: K reverse linked list
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
ListNode* reverseLL(ListNode* head)
{
    if(!head || !head->next)
        return head;
    ListNode* p = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return p;
}
ListNode* Solution::reverseList(ListNode* A, int B) 
{
    if(!A || !A->next)
        return A;
    ListNode *temp, *l, *f, *lnext, *tmp;
    int N = 0;
    temp = A;
    while(temp)
    {
        N++;
        temp = temp->next;
    }
    if(B == 1)
        return A;
    if(B == N)
        return reverseLL(A);
    temp = A;
    for(int i = 0; i<N/B; i++)
    {
        f = temp;
        for(int j = 0; j<B-1; j++)
        {
            temp = temp->next;
        }
        l = temp;
        lnext = l->next;
        l->next = NULL;
        if(i == 0)
            A = reverseLL(f);
        else
            tmp->next = reverseLL(f);
        tmp = A;
        while(tmp->next)
            tmp = tmp->next;
        temp = lnext;
    }
    return A;
}
