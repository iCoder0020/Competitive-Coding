/*
ID: ishan-sang
PROG: Root to Leaf Paths With Sum
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
void helper(vector<vector<int>> &ans, vector<int> &v, TreeNode *A, int sum, int target)
{
    if(!A->left && !A->right)
    {
        if(sum + A->val == target)
        {
            v.push_back(A->val);
            ans.push_back(v);
            v.pop_back();
        }
        return;
    }
    if(A->left)
    {
        v.push_back(A->val);   
        helper(ans, v, A->left, sum+A->val, target);
        v.pop_back();
    }
    if(A->right)
    {
        v.push_back(A->val);
        helper(ans, v, A->right, sum+A->val, target);
        v.pop_back();
    }
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) 
{
    vector<vector<int>> ans;
    vector<int> v;
    if(!A)
        return ans;
    helper(ans, v, A, 0, B);
    return ans;
}
