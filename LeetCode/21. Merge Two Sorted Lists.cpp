/*
ID: iCoder0020
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode *c = NULL, *c_head = NULL;
        if(!a & !b)
            return c_head;
        if(!a)
            return b;
        if(!b)
            return a;
        if(a->val < b->val)
        {
            c = a;
            a = a->next;
        }
        else
        {
            c = b;
            b = b->next;
        }
        c_head = c;
        while(a && b)
        {
            if(a->val < b->val)
            {
                c->next = a;
                a = a->next;
                c = c->next;
            }
            else
            {
                c->next = b;
                b = b->next;
                c = c->next;
            }
        }
        while(a)
        {
            c->next = a;
            a = a->next;
            c = c->next;
        }
        while(b)
        {
            c->next = b;
            b = b->next;
            c = c->next;
        }
        c->next = NULL;
        return c_head;
    }
};