/*
ID: ishan-sang
PROG: Add Two Numbers as Lists
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
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) 
{
    if(!A)
        return B;
    if(!B)
        return A;
    int s1,s2,carry = 0, sum;
    ListNode *a, *b, *c, *C;
    a = A;
    b = B;
    c = new ListNode(-1);
    C = c;
    while(a || b)
    {
        s1 = s2 = 0;
        if(a)
        {
            s1 = a->val;
            a = a->next;
        }
        if(b)
        {
            s2 = b->val;
            b = b->next;
        }
        // cout<<s1<<" "<<s2<<" "<<carry<<endl;
        sum = s1+s2+carry;
        carry = (sum)/10;
        c->next = new ListNode(sum%10);
        c = c->next;
    }
    if(carry)
    {
        c->next = new ListNode(carry);
        c = c->next;
    }
    c->next = NULL;
    C = C->next;
    return C;
}
