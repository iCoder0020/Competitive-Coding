/*
ID: ishan-sang
PROG: Rotate List
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
ListNode* Solution::rotateRight(ListNode* A, int B) 
{
    ListNode *tmp = A, *tail, *newhead;
    int N = 0;
    while(tmp)
    {
        N++;
        if(tmp->next == NULL)
            tail = tmp;
        tmp = tmp->next;
    }
    if(B>N)
        B = B%N;
    if(B%N == 0)
        return A;
    tmp = A;
    for(int n = 0; n<N-B-1; n++)
    {
        tmp = tmp->next;
    }
    newhead = tmp->next;
    tmp->next = NULL;
    tail->next = A;
    return newhead;
}
