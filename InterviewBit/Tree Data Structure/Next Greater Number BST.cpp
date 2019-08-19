/*
ID: ishan-sang
PROG: Next Greater Number BST
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
TreeNode* Solution::getSuccessor(TreeNode* A, int B) 
{
    stack<TreeNode*>S;
    TreeNode *temp = A, *ans = NULL;
    bool flag = false;
    while(temp || !S.empty())
    {
        while(temp)
        {
            S.push(temp);
            temp = temp->left;
        }
        temp = S.top();
        S.pop();
        if(flag)
        {
            ans = temp;
            flag = false;
        }
        if(temp->val == B)
            flag = true;
        temp = temp->right;
    }
    return ans;
}
