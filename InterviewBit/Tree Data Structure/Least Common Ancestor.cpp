/*
ID: ishan-sang
PROG: Least Common Ancestor
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
#define MOD 1003
void helper(long long int &ans, vector<int> &v, TreeNode *A)
{
    if(!A)
        return;
    if(!A->left && !A->right)
    {
        int num = 0;
        for(auto it: v)
            num = (num*10 + it)%MOD;
        num = (num*10 + A->val)%MOD;
        ans = (ans + num)%MOD;
        return;
    }
    v.push_back(A->val);
    if(A->left)
        helper(ans, v, A->left);
    if(A->right)
        helper(ans, v, A->right);
    v.pop_back();
}
int Solution::sumNumbers(TreeNode* A) 
{
    long long int ans = 0;
    vector<int>v;
    helper(ans, v, A);
    return ans;
}
