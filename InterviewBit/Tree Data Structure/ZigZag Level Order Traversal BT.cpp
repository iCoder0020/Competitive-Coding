/*
ID: ishan-sang
PROG: ZigZag Level Order Traversal BT
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) 
{
    queue<pair<int,TreeNode*>>Q;
    vector<vector<int>> ans;
    map<int, vector<int>>M;
    if(A)
        Q.push({0,A});
    while(!Q.empty())
    {
        int lvl = Q.front().first;
        TreeNode* temp = Q.front().second;
        M[lvl].push_back(temp->val);
        Q.pop();
        if(temp->left)
            Q.push({lvl+1, temp->left});
        if(temp->right)
            Q.push({lvl+1, temp->right});
    }
    for(auto it: M)
    {
        vector<int> v = it.second;
        if(it.first&1)
            reverse(v.begin(), v.end());
        ans.push_back(v);
    }
    return ans;
}
