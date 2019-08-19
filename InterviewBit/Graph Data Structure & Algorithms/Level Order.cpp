/*
ID: ishan-sang
PROG: Level Order
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
int find_height(TreeNode* A)
{
    if(!A)
        return 0;
    return max(find_height(A->left), find_height(A->right))+1;
}
vector<vector<int> > Solution::levelOrder(TreeNode* A) 
{
    int h = find_height(A);
    vector<vector<int>> v(h);
    queue<pair<int,TreeNode*>>Q;
    Q.push({0,A});
    while(!Q.empty())
    {
        int lvl = Q.front().first;
        TreeNode* node = Q.front().second;
        Q.pop();
        v[lvl].push_back(node->val);
        if(node->left)
            Q.push({lvl+1, node->left});
        if(node->right)
            Q.push({lvl+1, node->right});
    }
    return v;
}
