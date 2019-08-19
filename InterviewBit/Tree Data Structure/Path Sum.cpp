/*
ID: ishan-sang
PROG: Path Sum
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
int helper(TreeNode *A, int sum, int target)
{
    if(!A->left && !A->right)
    {
        if(sum +A->val == target)
            return 1;
        return 0;
    }
    if(A->left && A->right)
        return (helper(A->left, sum+A->val, target) || helper(A->right, sum+A->val, target));
    if(A->left)
        return helper(A->left, sum+A->val, target);
    if(A->right)
        return helper(A->right, sum+A->val, target);
}
int Solution::hasPathSum(TreeNode* A, int B) 
{
    return helper(A, 0, B);
}
