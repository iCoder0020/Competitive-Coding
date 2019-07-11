/*
ID: iCoder0020
PROG: Range Sum of BST
LANG: C++                  
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sum;
    void helper(TreeNode* root, int L, int R)
    {
        if(!root)
            return;
        if(root->left)
            helper(root->left, L, R);
        if(root->val >= L && root->val <=R)
            sum += root->val;
        if(root->right)
            helper(root->right, L, R);
    }
    int rangeSumBST(TreeNode* root, int L, int R) 
    {
        sum = 0;
        helper(root, L, R);
        return sum;
    }
};