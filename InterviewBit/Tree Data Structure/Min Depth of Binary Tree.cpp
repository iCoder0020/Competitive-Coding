/*
ID: ishan-sang
PROG: Min Depth of Binary Tree
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
int helper(TreeNode* A)
{
    if(!A->left && !A->right)
        return 1;
    int l = INT_MAX, r = INT_MAX;
    if(A->left)
        l = 1 + helper(A->left);
    if(A->right)
        r = 1 + helper(A->right);
    return min(l, r);
}
int Solution::minDepth(TreeNode* A) 
{
    if(!A)
        return 0;
    return helper(A);
}
