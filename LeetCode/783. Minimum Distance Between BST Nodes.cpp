/*
ID: iCoder0020
PROG: Minimum Distance Between BST Nodes
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
    vector<int> arr;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) 
    {
        arr.clear();
        int min_diff = INT_MAX;
        inorder(root);
        for(int n = 1; n<arr.size(); n++)
            min_diff = min(min_diff, arr[n] - arr[n-1]);
        return min_diff;
    }
};