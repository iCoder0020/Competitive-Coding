/*
ID: ishan-sang
PROG: Balanced Binary Tree
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
int Solution::isBalanced(TreeNode* A) 
{
    if(!A)
        return 1;
    if(!A->left && !A->right)
        return 1;
    if(!A->left)
        if(A->right->left || A->right->right)
            return 0;
    if(!A->right)
        if(A->left->left || A->left->right)
            return 0;
    return (isBalanced(A->left) && isBalanced(A->right));
}
