/*
ID: ishan-sang
PROG: Invert the Binary Tree
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
TreeNode* mirror(TreeNode* root, TreeNode* A, TreeNode* B)
{
    root->left = B, root->right = A;
    if(A)
        A = mirror(A, A->left, A->right);
    if(B)
        B = mirror(B, B->left, B->right);
    return root;
}
TreeNode* Solution::invertTree(TreeNode* A) 
{
    return mirror(A, A->left, A->right);
}
