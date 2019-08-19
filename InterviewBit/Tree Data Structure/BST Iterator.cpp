/*
ID: ishan-sang
PROG: BST Iterator
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
stack<TreeNode*>Smin;
BSTIterator::BSTIterator(TreeNode *root) 
{
    while(!Smin.empty())
        Smin.pop();
    TreeNode *temp = root;
    while(temp)
    {
        Smin.push(temp);
        temp = temp->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() 
{
    if(!Smin.empty())
        return true;
    return false;
}

/** @return the next smallest number */
int BSTIterator::next() 
{
    TreeNode *temp = Smin.top();
    int x = temp->val;
    Smin.pop();
    temp = temp->right;
    while(temp)
    {
        Smin.push(temp);
        temp = temp->left;
    }
    return x;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
