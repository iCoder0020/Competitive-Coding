/*
ID: iCoder0020
PROG: Longest Univalue Path
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
    int max_ans;
    int helper(TreeNode* root, int prev)
    {
        if(!root)
            return 0;
        int c = (root->val == prev)?1:0;
        int l = helper(root->left, root->val);
        int r = helper(root->right, root->val);
        int s = max(l+c, r+c);
        // cout<<root->val<<" "<<c<<" "<<l<<" "<<r<<endl;
        max_ans = max(max_ans,max(s, (l+r)));
        return (root->val == prev)?s:0;        
    }
    int longestUnivaluePath(TreeNode* root) 
    {
        max_ans = 0;
        int dump = helper(root, -1);
        return max_ans;
    }
};