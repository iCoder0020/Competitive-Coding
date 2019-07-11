/*
ID: iCoder0020
PROG: Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<pair<TreeNode*,int>>Q;
        Q.push({root,0});
        map<int, vector<int>>M;
        while(!Q.empty())
        {
            pair<TreeNode*,int> p = Q.front();
            Q.pop();
            TreeNode* node = p.first;
            int lvl = p.second;
            M[lvl].push_back(node->val);
            if(node->left)
                Q.push({node->left, lvl+1});
            if(node->right)
                Q.push({node->right, lvl+1});
        }
        for(auto it: M)
            ans.push_back(it.second);
        return ans;
    }
};