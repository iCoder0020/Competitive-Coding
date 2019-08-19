/*
ID: ishan-sang
PROG: Construct Binary Tree From Inorder And Preorder
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
int p;
TreeNode* helper(vector<int> &A, vector<int> &B, int l, int r)
{
    if(l>r)
        return nullptr;
    int x = A[p], i;
    for(i = l; i<=r; i++)
        if(B[i] == x)
            break;
    TreeNode* t = new TreeNode(x);
    p++;
    t->left = helper(A, B, l, i-1);
    t->right = helper(A, B, i+1, r);
    return t;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    p = 0;
    return helper(A, B, 0, B.size()-1);
}
