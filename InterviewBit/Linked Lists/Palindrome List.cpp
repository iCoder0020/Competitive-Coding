/*
ID: ishan-sang
PROG: Palindrome List
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
ListNode* reverseLL(ListNode *A)
{
    if(A == NULL || A->next == NULL)
        return A;
    ListNode* p = reverseLL(A->next);
    A->next->next = A;
    A->next = NULL;
    return p;
}
int Solution::lPalin(ListNode* A) 
{
    string first = "", last = "";
    ListNode *temp = A, *tmp = A;
    int N = 0;
    while(temp)
    {
        N++;
        temp = temp->next;
    }
    int n = 0;
    int mid = N/2;
    temp = A;
    while(n<mid)
    {
        temp = temp->next;
        n++;
    }
    if(N&1)
        temp = temp->next;
    temp = reverseLL(temp);
    while(tmp && temp)
    {
        if(temp->val != tmp->val)
            return 0;
        tmp = tmp->next;
        temp = temp->next;
    }
    return 1;
}
