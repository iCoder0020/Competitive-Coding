/*
ID: ishan-sang
PROG: Binary Tree From Inorder And Postorder
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
        return NULL;
    int i, x = B[p];
    for(i = l; i<=r; i++)
        if(A[i] == x)
            break;
    TreeNode *t = new TreeNode(x);
    p--;
    t->right = helper(A,B,i+1,r);
    t->left = helper(A,B,l,i-1);
    return t;
        
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) 
{
    p = B.size()-1;
    return helper(A, B, 0, A.size()-1);
}
