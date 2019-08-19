/*
ID: ishan-sang
PROG: Valid Binary Search Tree
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
int helper(TreeNode *A, int min, int max)
{
    // cout<<A->val<<" "<<min<<" "<<max<<endl;
    if(A->val <= min || A->val >= max)
        return 0;
    if(!A || (!A->left && !A->right) )
        return 1;
    if(A->left && A->right)
        return ((A->left->val < A->val) && helper(A->left, min, A->val) && (A->right->val > A->val) && helper(A->right, A->val, max));
    if(A->left)
        return ((A->left->val < A->val) && helper(A->left, min, A->val));
    if(A->right)
        return ((A->right->val > A->val) && helper(A->right, A->val, max));
    
}
int Solution::isValidBST(TreeNode* A) 
{
    return helper(A, INT_MIN, INT_MAX);
}
