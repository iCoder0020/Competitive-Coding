/*
ID: iCoder0020
PROG: Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) 
    {
        if(!head || !head->next)
            return NULL;
        ListNode *slow = head->next;
        ListNode *fast = head->next->next;
        while(slow != fast)
        {
            slow = slow->next;
            if(!fast || !fast->next)
                return NULL;
            fast = fast->next->next;
        }
        slow = head;
        while(1)
        {
            if(slow == fast)
                return slow;
            slow = slow->next;
            fast = fast->next;
        }
        
    }
};