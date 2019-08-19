/*
ID: ishan-sang
PROG: Unique Binary Search Trees
LANG: C++                  
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<TreeNode*> construct(int start, int end)
{
    vector<TreeNode*> v;
    if(start > end)
    {
        v.push_back(nullptr);
        return v;
    }
    
    for(int i = start; i<=end; i++)
    {
        vector<TreeNode*> l = construct(start, i-1);
        vector<TreeNode*>r = construct(i+1, end);
        
        for(int j = 0; j<l.size(); j++)
        {
            for(int k = 0; k<r.size(); k++)
            {
                TreeNode* root = new TreeNode(i);
                root->left = l[j];
                root->right = r[k];
                v.push_back(root);
            }
        }
    }
    return v;
}

vector<TreeNode*> Solution::generateTrees(int N) 
{
    return construct(1, N);
}
