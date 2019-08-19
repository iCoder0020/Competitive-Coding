/*
ID: ishan-sang
PROG: Remove Duplicates from Sorted List
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
ListNode* Solution::deleteDuplicates(ListNode* A) 
{
    ListNode *temp = A;
    int num;
    while(temp)
    {
        num = temp->val;
        while(temp->next && temp->next->val == num)
        {
            temp->next = temp->next->next;
        }
        if(temp)
            temp = temp->next;
    }
    return A;
}
