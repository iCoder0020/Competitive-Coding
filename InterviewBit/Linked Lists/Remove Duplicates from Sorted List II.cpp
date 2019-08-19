/*
ID: ishan-sang
PROG: Remove Duplicates from Sorted List II
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
    ListNode* temp = A;
    ListNode *head = NULL, *perhead = NULL;
    int num;
    bool flag;
    while(temp)
    {
        num = temp->val;
        flag = false;
        while(temp->next && temp->next->val == num)
        {
            temp->next = temp->next->next;
            flag = true;
        }
        if(!flag)
        {
            if(!head)
            {
                head = temp;
                perhead = head;
            }
            else
            {
                head->next = temp;
                head = head->next;
            }
        }
        temp = temp->next;
    }
    if(head)
        head->next = NULL;
    return perhead;
}
