/*
ID: ishan-sang
PROG: 2-Sum Binary Tree
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
int Solution::t2Sum(TreeNode* A, int B) 
{
    stack<TreeNode*>Smin;
    stack<TreeNode*>Smax;
    TreeNode* temp;
    if(!A)
        return 0;
    temp = A;
    while(temp)
    {
        Smin.push(temp);
        temp = temp->left;
    }
    temp = A;
    while(temp)
    {
        Smax.push(temp);
        temp = temp->right;
    }
    
    while(1)
    {
        TreeNode *l, *r;
        l = Smin.top();
        r = Smax.top();
        // cout<<l->val<<" "<<r->val<<endl;
        if(l == r)
            break;
        if(l->val+r->val == B)
            return 1;
        else if(l->val + r->val > B)
        {
            Smax.pop();
            if(r->left)
            {
                temp = r->left;
                while(temp)
                {
                    Smax.push(temp);
                    temp = temp->right;
                }
            }
        }
        else
        {
            Smin.pop();
            if(l->right)
            {
                temp = l->right;
                while(temp)
                {
                    Smin.push(temp);
                    temp = temp->left;
                }
            }
        }
    }
    
    return 0;
}
