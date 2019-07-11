/*
ID: iCoder0020
PROG: Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*>S;
        vector<int>v;
        
        if(root)
            S.push(root);
        
        while(!S.empty())
        {
            TreeNode* temp = S.top();
            S.pop();
            v.push_back(temp->val);
            if(temp->right)
                S.push(temp->right);
            if(temp->left)
                S.push(temp->left);
        }
        return v;
    }
};  