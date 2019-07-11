/*
ID: iCoder0020
PROG: Palindrome Linked List
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
    bool isPalindrome(ListNode* head) 
    {
        if(!head || !head->next)
            return true;
        int len = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            tmp = tmp->next;
            len++;
        }
        int m = len/2;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* start = head;
        for(int i = 0; i<m; i++)
            start = start->next;
        if(len&1)
            start = start->next;
        cout<<m<<endl;
        while(m--)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        tmp = prev;
        while(tmp && start)
        {
            if(tmp->val != start->val)
                return false;
            tmp = tmp->next;
            start = start->next;
        }
        return true;   
    }
};