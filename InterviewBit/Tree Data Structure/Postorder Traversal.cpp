/*
ID: ishan-sang
PROG: Postorder Traversal
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
vector<int> Solution::postorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    stack<TreeNode*>S;
    if(A)
        S.push(A);
    while(!S.empty())
    {
        TreeNode* temp = S.top();
        S.pop();
        ans.push_back(temp->val);
        if(temp->left)
            S.push(temp->left);
        if(temp->right)
            S.push(temp->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
