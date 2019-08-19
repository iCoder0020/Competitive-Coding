/*
ID: ishan-sang
PROG: Merge Two Sorted Lists
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
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    if(!A)
        return B;
    if(!B)
        return A;
    ListNode *a = A, *b = B, *c;
    ListNode *temp ;
    ListNode *head = new ListNode(0);
    c = head;
    while(a && b)
    {
        if(a->val < b->val)
        {
            temp = new ListNode(a->val);
            a = a->next;
        }
        else
        {
            temp = new ListNode(b->val);
            b = b->next;
        }
        c->next = temp;
        c = c->next;
    }
    while(a)
    {
        temp = new ListNode(a->val);
        a = a->next;
        c->next = temp;
        c = c->next;
    }
    while(b)
    {
        temp = new ListNode(b->val);
        b = b->next;
        c->next = temp;
        c = c->next;
    }
    return head->next;
}
