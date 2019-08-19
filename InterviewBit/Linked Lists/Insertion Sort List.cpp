/*
ID: ishan-sang
PROG: Insertion Sort List
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
ListNode* Solution::insertionSortList(ListNode* A) 
{
    if(!A || !A->next)
        return A;
    ListNode *prevcurr, *curr, *prevtemp, *temp, *curr2;
    int num;
    prevcurr = A;
    curr = A->next;
    while(curr)
    {
        num = curr->val;
        prevtemp = NULL;
        temp = A;
        while(temp && temp->val < num && temp!=curr)
        {
            prevtemp = temp;
            temp = temp->next;
        }
        if(temp!=curr)
        {
            if(temp == A)
            {
                curr2 = curr;
                prevcurr->next = curr->next;
                curr->next = A;
                A = curr;
                curr = curr2;
            }
            else
            {
                curr2 = curr;
                prevcurr->next = curr->next;
                prevtemp->next = curr;
                curr->next = temp;
                curr = prevcurr;
            }
        }
        // cout<<num<<": ";
        // curr2 = curr;
        // curr = A;
        // while(curr != curr2)
        // {
        //     cout<<curr->val<<" ";
        //     curr = curr->next;
        // }
        // cout<<curr->val<<endl;
        // curr = curr2;
        prevcurr = curr;
        curr = curr->next;
    }
    return A;
}
