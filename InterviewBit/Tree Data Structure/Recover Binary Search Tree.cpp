/*
ID: ishan-sang
PROG: Recover Binary Search Tree
LANG: C++                  
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::recoverTree(TreeNode* A) 
{
    set<int>ans;
    stack<TreeNode*>S;
    TreeNode *temp = A, *prev = nullptr, *curr, *next;
    while(temp)
    {
        S.push(temp);
        temp = temp->left;
    }
    curr = S.top();
    S.pop();
    temp = curr->right;
    while(temp)
    {
        S.push(temp);
        temp = temp->left;
    }
    while(!S.empty())
    {
        next = S.top();
        S.pop();
        temp = next->right;
        while(temp)
        {
            S.push(temp);
            temp = temp->left;
        }
        if(!prev)
        {
            if(curr->val > next->val)
                ans.insert(curr->val);
        }
        else
        {
            if(curr->val < prev->val || curr->val > next->val)
                ans.insert(curr->val);
            else if(curr->val > next->val || prev->val > next->val)
                ans.insert(next->val);
        }
        prev = curr;
        curr = next;
    }
    if(!prev)
    {
        if(curr->val > next->val)
            ans.insert(curr->val);
    }
    else
    {
        if(curr->val < prev->val || curr->val > next->val)
            ans.insert(curr->val);
        else if(curr->val > next->val || prev->val > next->val)
            ans.insert(next->val);
    }
    vector<int>v (ans.begin(), ans.end());
    vector<int>v1 = {v[0], v[v.size()-1]};
    return v1;
}
