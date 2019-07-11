/*
ID: iCoder0020
PROG: Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;
        ListNode* temp2;
        int a, b, s, c = 0;
        while(l1 && l2)
        {
            a = l1->val;
            b = l2->val;
            temp2 = new ListNode((a+b+c)%10);
            temp->next = temp2;
            temp = temp->next;
            c = (a+b+c)/10;
            l1 = l1->next;
            l2 = l2->next;
        } 
        while(l1)
        {
            a = l1->val;
            temp2 = new ListNode((a+c)%10);
            temp->next = temp2;
            temp = temp->next;
            c = (a+c)/10;
            l1 = l1->next;
        }
        while(l2)
        {
            b = l2->val;
            temp2 = new ListNode((b+c)%10);
            temp->next = temp2;
            temp = temp->next;
            c = (b+c)/10;
            l2 = l2->next;
        }
        if(c == 1)
        {
            temp2 = new ListNode(1);
            temp->next = temp2;
            temp = temp->next;
        }
        return head->next;
    }
};