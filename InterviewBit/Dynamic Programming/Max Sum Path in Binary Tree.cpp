/*
ID: ishan-sang
PROG: Max Sum Path in Binary Tree
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
int f(TreeNode* root, int &res)
{
    if(!root)
        return 0;
    int l = f(root->left, res);
    int r = f(root->right, res);
    int t = max(root->val, root->val + max(l,r));
    int w = max(t, l + r + root->val);
    res = max(res, w);
    return t;
    
}
int Solution::maxPathSum(TreeNode* A) 
{
    int res = INT_MIN;
    f(A, res);
    return res;
}
