/*
ID: iCoder0020
PROG: Count Complete Tree Nodes
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
class Solution 
{
public:
    int cnt = 0;
    int countNodes(TreeNode* root) 
    {
        if(!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};