/*
ID: ishan-sang
PROG: Kth Smallest Element In Tree
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
map<TreeNode*, int> lsize;
map<TreeNode*, int> rsize;
map<TreeNode*, int> size;
int get_size(TreeNode* A)
{
    if(!A)
        return 0;
    if(size.find(A) != size.end())
        return size[A];
    int l,r;
    if(size.find(A->left) != size.end())
        l = size[A->left];
    else
        l = get_size(A->left);
    if(size.find(A->right) != size.end())
        r = size[A->right];
    else
        r = get_size(A->right);
    size[A] = l+r+1;
    return size[A];
    
}
int Solution::kthsmallest(TreeNode* A, int B) 
{
    int x = get_size(A->left) + 1;
    // cout<<x<<" "<<B<<endl;
    if(x == B)
        return A->val;
    else if(x<B)
        return kthsmallest(A->right, B-x);
    return kthsmallest(A->left, B);
}
