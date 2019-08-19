/*
ID: ishan-sang
PROG: Sorted Array To Balanced BST
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
TreeNode* helper(const vector<int> &A, int l, int r)
{
    if(l>r)
        return nullptr;
    int m = (r+l)/2;
    TreeNode* t = new TreeNode(A[m]);
    t->left = helper(A, l, m-1);
    t->right = helper(A, m+1, r);
    return t;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) 
{
    return helper(A, 0, A.size()-1);
}
