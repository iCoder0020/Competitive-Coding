/*
ID: iCoder0020
PROG: Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        stack<TreeNode*> S;
        vector<int> v;
        
        if(root)
            S.push(root);
        
        while(!S.empty())
        {
            TreeNode* last = S.top();
            S.pop();
            
            v.push_back(last->val);
            
            if(last->left)
                S.push(last->left);
            
            if(last->right)
                S.push(last->right);
            
        }
        reverse(v.begin(), v.end());
        return v;
    }
};