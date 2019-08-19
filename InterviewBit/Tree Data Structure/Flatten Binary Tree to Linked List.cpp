/*
ID: ishan-sang
PROG: Flatten Binary Tree to Linked List
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
pair<TreeNode*, TreeNode*> f(TreeNode* &A)
{
    if(!A || (!A->left && !A->right))
        return {A,A};
    pair<TreeNode*, TreeNode*>pl , pr;
    pl = f(A->left);
    pr = f(A->right);
    if(pl.first && pr.first)
    {
        A->right = pl.first;
        pl.second->right = pr.first;
        pr.second->right = nullptr;
        A->left = nullptr;
        return {A, pr.second};
    }
    else if(pl.first)
    {
        A->right = pl.first;
        pl.second->right = nullptr;
        A->left = nullptr;
        return {A, pl.second};
    }
    else if(pr.first)
    {
        A->right = pr.first;
        pr.second->right = nullptr;
        A->left = nullptr;
        return {A, pr.second};
    }
}

TreeNode* Solution::flatten(TreeNode* A) 
{
    return f(A).first;
}
