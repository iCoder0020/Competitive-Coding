/*
ID: ishan-sang
PROG: Reverse Link List II
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
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    if(!A || !A->next || B == C)
        return A;
    ListNode *first, *last, *tmp, *mid1, *mid2;
    tmp = A;
    int N = 0;
    while(tmp)
    {
        tmp = tmp->next;
        N++;
    }
    tmp = A;
    if(B == 1 && C == N)
        return reverseLL(A);
    if(B == 1)
    {
       for(int i = 0; i<C-1; i++)
            tmp = tmp->next;
        mid2 = tmp;
        last = mid2->next;
        mid2->next = NULL;
        tmp = reverseLL(A);
        A = tmp;
        while(tmp)
        {
            if(tmp->next == NULL)
            {
                tmp->next = last;
                break;
            }
            tmp = tmp->next;
        }
    }
    else if(C == N)
    {
        for(int i = 0; i<B-2; i++)
            tmp = tmp->next;
        first = tmp;
        mid1 = first->next;
        first->next = reverseLL(mid1);
    }
    else
    {
        for(int i = 0; i<B-2; i++)
            tmp = tmp->next;
        first = tmp;
        mid1 = first->next;
        for(int i = 0; i<C-B+1; i++)
            tmp = tmp->next;
        mid2 = tmp;
        last = mid2->next;
        mid2->next= NULL;
        first->next = reverseLL(mid1);
        tmp = A;
        while(tmp)
        {
            if(tmp->next == NULL)
            {
                tmp->next = last;
                break;
            }
            tmp = tmp->next;
        }
    }
    return A;
}
