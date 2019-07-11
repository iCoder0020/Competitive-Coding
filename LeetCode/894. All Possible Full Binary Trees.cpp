/*
ID: iCoder0020
PROG: All Possible Full Binary Trees
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
    vector<TreeNode*> f(int N)
    {
        vector<TreeNode*>ret;
        if(N==1)
        {
            TreeNode *root=new TreeNode(0);
            ret.push_back(root);
            return ret;
        }
        N--;
        for(int i=1; i<=N-1; i+=2)
        {
            vector<TreeNode*>l=f(i);
            vector<TreeNode*>r=f(N-i);
        
            for(auto lroot: l)
            {
                for(auto rroot: r)
                {
                    TreeNode *root=new TreeNode(0);
                    root->left=lroot;
                    root->right=rroot;
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
    
    vector<TreeNode*> allPossibleFBT(int N) 
    {
        return f(N);    
    }
};