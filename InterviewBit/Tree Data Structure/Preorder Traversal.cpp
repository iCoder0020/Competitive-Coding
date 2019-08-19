/*
ID: ishan-sang
PROG: Preorder Traversal
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
vector<int> Solution::preorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    stack<TreeNode*>S;
    TreeNode *temp = A;
    while(temp || !S.empty())
    {
        while(temp)
        {
            S.push(temp);
            ans.push_back(temp->val);
            temp = temp->left;
        }
        temp = S.top();
        S.pop();
        temp = temp->right;
    }
    return ans;
}
