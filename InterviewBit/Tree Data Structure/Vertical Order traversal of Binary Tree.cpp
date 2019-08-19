/*
ID: ishan-sang
PROG: Vertical Order traversal of Binary Tree
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
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) 
{
    vector<vector<int>> ans;
    TreeNode* curr = A;
    int x = 0;
    if(!curr)
        return ans;
    map<int, vector<int>> M;
    queue<pair<TreeNode*,int>>Q;
    Q.push({curr, x});
    while(!Q.empty())
    {
        curr = Q.front().first;
        x = Q.front().second;
        M[x].push_back(curr->val);
        Q.pop();
        if(curr->left)
            Q.push({curr->left, x-1});
        if(curr->right)
            Q.push({curr->right, x+1});
    }
    for(auto it: M)
        ans.push_back(it.second);
    return ans;
}
