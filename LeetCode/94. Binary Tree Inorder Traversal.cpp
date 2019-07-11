/*
ID: iCoder0020
PROG: Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        stack <TreeNode*> S;
        vector<int>v;
        if(root)
            S.push(root);
        while(!S.empty())
        {
            TreeNode* temp = S.top();
            S.pop();
            
            if(!temp->left && !temp->right)
            {
                v.push_back(temp->val);
                continue;
            }
            
            if(temp->right)
                S.push(temp->right);
            TreeNode* t = new TreeNode(temp->val);
            S.push(t);
            if(temp->left)
                S.push(temp->left);
            
        }
        return v;
    }
};