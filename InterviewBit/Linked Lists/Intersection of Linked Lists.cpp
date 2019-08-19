/*
ID: ishan-sang
PROG: Intersection of Linked Lists
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
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) 
{
    ListNode* ans = NULL;
    ListNode *temp, *temp1;
    ListNode *Acopy = A, *Bcopy = B;
    int a = 0, b = 0;
    temp = A;
    while(temp)
    {
        a++;
        temp = temp->next;
    }
    temp = B;
    while(temp)
    {
        b++;
        temp = temp->next;
    }
    // cout<<a<<" "<<b<<endl;
    if(a>b)
    {
        A = Bcopy;
        B = Acopy;
    }
    temp = B;
    temp1 = A;
    for(int n = 0; n<abs(b-a); n++)
        temp = temp->next;

    while(temp && temp1)
    {
        // cout<<temp->val<<" "<<temp1->val<<endl;
        if(temp == temp1)
        {
            ans = temp;
            break;
        }
        temp = temp->next;
        temp1 = temp1->next;
    }
    if(a>b)
    {
        A = Acopy;
        B = Bcopy;
    }
    return ans;
}
