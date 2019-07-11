/*
ID: iCoder0020
PROG: Next Greater Node In Linked List
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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>arr;
        stack<int>nge;
        vector<int>ans;
        int N = 0;
        if(!head)
            return ans;
        while(head)
        {
            arr.push_back(head->val);
            head = head->next;    
            N++; 
        }
        int n = N-1;
        nge.push(arr[n]);
        ans.push_back(0);
        while(n--)
        {
            if(arr[n] < nge.top())
                ans.push_back(nge.top());
            else
            {
                while(!nge.empty() && arr[n] >= nge.top())
                    nge.pop();
                if(nge.empty())
                    ans.push_back(0);
                else
                    ans.push_back(nge.top());
            }
            nge.push(arr[n]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};