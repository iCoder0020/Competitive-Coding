/*
ID: iCoder0020
PROG: All Nodes Distance K in Binary Tree
LANG: C++                  
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    map<TreeNode*, vector<TreeNode*>>g;
    map<TreeNode*, bool>vis;
    void inorder(TreeNode* root)
    {
        if(!root)
            return;
        inorder(root->left);
        if(root->left)
        {
            g[root->left].push_back(root);
            g[root].push_back(root->left);
        }
        if(root->right)
        {
            g[root->right].push_back(root);
            g[root].push_back(root->right);
        }
        inorder(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        vector<int>v;
        inorder(root);
        vector<TreeNode*> lvl;
        queue<pair<TreeNode*, int>>Q;
        Q.push({target, 0});
        while(!Q.empty())
        {
            TreeNode* temp = Q.front().first;
            int level = Q.front().second;
            if(level == K)
                v.push_back(temp->val);
            vis[temp] = true;
            Q.pop();
            for(auto it: g[temp])
            {
                if(vis.find(it) == vis.end())
                    Q.push({it, level+1});
            }
        }
        return v;
    }
};




OR





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    vector<char>path;
    vector<int>v;
    bool findPath(TreeNode* root, TreeNode* target)
    {
        if(!root)
            return false;
        if(root == target)
        {
            path.push_back('C');
            return true;
        }
        if(root->left)
        {
            path.push_back('L');
            if(findPath(root->left, target))
                return true;
            path.pop_back();
        }
        if(root->right)
        {
            path.push_back('R');
            if(findPath(root->right, target))
                return true;
            path.pop_back();
        }
        return false;
    }
    void findNodes(TreeNode* root, int K)
    {
        if(!root || K<0)
            return;
        if(K == 0)
        {
            v.push_back(root->val);
            return;
        }
        findNodes(root->left, K-1);
        findNodes(root->right, K-1);    
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        findPath(root, target);
        int N = path.size();
        TreeNode* curr = root;
        for(int i = 0; i<N; i++)
        {
            if(i == N-K-1)
                v.push_back(curr->val);
            if(path[i] == 'L')
            {
                findNodes(curr->right, K-N+i);
                curr = curr->left;
            }
            else if(path[i] == 'R')
            {
                findNodes(curr->left, K-N+i);
                curr = curr->right;
            }
            else
            {
                findNodes(curr->left, K-1);
                findNodes(curr->right, K-1);
            }
        }
        return v;
    }
};