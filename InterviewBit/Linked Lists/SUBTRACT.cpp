/*
ID: ishan-sang
PROG: SUBTRACT
LANG: C++                  
*/

void reverseLL(ListNode **head)
{
    ListNode *current = *head, *p = NULL, *n = NULL;;
    while (current != NULL) 
    { 
        n = current->next; 
        current->next = p; 
        p = current; 
        current = n; 
    } 
    *head = p; 
}
ListNode* Solution::subtract(ListNode* A) 
{
    if(!A || !A->next)
        return A;
    ListNode *f, *l, *mid, *temp;
    int N = 0;
    temp = A;
    while(temp)
    {
        N++;
        temp = temp->next;
    }
    temp = A;
    for(int i = 0; i<(N+1)/2-1; i++)
        temp = temp->next;
    f = A;
    mid = temp;
    l = mid->next;
    mid->next = NULL;
    reverseLL(&l);
    temp = l;
    for(int i = 0; i<N/2; i++)
    {
        f->val = l->val - f->val;
        f = f->next;
        l = l->next;
    }
    reverseLL(&temp);
    mid->next = temp;
    return A;
}
