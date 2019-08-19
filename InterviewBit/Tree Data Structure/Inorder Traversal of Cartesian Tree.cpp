/*
ID: ishan-sang
PROG: Inorder Traversal of Cartesian Tree
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
TreeNode* helper(vector<int> &A, int l, int r)
{
    if(l>r)
        return NULL;
    int maxm = INT_MIN, maxi;
    for(int i = l; i<=r; i++)
    {
        if(A[i] > maxm)
        {
            maxm = A[i];
            maxi = i;
        }
    }
    TreeNode* t = new TreeNode(A[maxi]);
    t->left = helper(A, l, maxi-1);
    t->right = helper(A, maxi+1, r);
    return t;
}
TreeNode* Solution::buildTree(vector<int> &A) 
{
    return helper(A, 0, A.size()-1);
}
