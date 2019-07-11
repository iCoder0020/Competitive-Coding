/*
ID: iCoder0020
PROG: Vertical Order Traversal of a Binary Tree
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
    vector<vector<int>>v;
    vector<multiset<pair<int,int>>> traversal = vector<multiset<pair<int,int>>>(2000);
    void fillitup(TreeNode* root, int x, int y)
    {
        if(!root)
            return;
        traversal[x+999].insert({y,root->val});
        fillitup(root->left, x-1, y+1);
        fillitup(root->right, x+1, y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        fillitup(root, 0, 0);
        for(int x = 0; x<2000; x++)
        {
            if(!traversal[x].empty())
            {
                vector<int>a;
                for(auto it: traversal[x])
                    a.push_back(it.second);
                v.push_back(a);
            }
        }
        return v;
    }
};