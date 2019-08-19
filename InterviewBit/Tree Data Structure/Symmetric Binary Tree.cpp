/*
ID: ishan-sang
PROG: Symmetric Binary Tree
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
int mirror(TreeNode *A, TreeNode *B)
{
    if(!A && !B)
        return 1;
    if(!A || !B)
        return 0;
    if(A->val != B->val)
        return 0;
    return (mirror(A->left,B->right) && mirror(A->right, B->left));
}
int Solution::isSymmetric(TreeNode* A) 
{
    if(!A)
        return 1;
    return mirror(A->left, A->right);
}
