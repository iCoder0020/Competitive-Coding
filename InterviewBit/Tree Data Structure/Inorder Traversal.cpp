/*
ID: ishan-sang
PROG: Inorder Traversal
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
vector<int> Solution::inorderTraversal(TreeNode* A) 
{
    vector<int> ans;
    stack<TreeNode*>S;
    TreeNode* temp = A;
    while(temp || !S.empty())
    {
        while(temp)
        {
            S.push(temp);
            temp = temp->left;
        }
        temp = S.top();
        ans.push_back(temp->val);
        S.pop();
        temp = temp->right;
    }
    return ans;
}
