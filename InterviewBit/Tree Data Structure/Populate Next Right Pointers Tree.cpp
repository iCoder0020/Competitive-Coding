/*
ID: ishan-sang
PROG: Populate Next Right Pointers Tree
LANG: C++                  
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


// O(N) memory space
/*void Solution::connect(TreeLinkNode* A) 
{
    queue<pair<int,TreeLinkNode*>>Q;
    map<int, vector<TreeLinkNode*>>M;
    if(A)
        Q.push({0,A});
    while(!Q.empty())
    {
        int lvl = Q.front().first;
        TreeLinkNode* temp = Q.front().second;
        M[lvl].push_back(temp);
        Q.pop();
        if(temp->left)
            Q.push({lvl+1, temp->left});
        if(temp->right)
            Q.push({lvl+1, temp->right});
    }
    for(auto it: M)
    {
        int N = it.second.size();
        int n;
        for(n = 0; n<N-1; n++)
            it.second[n]->next = it.second[n+1];
        it.second[n]->next = nullptr;
    }
}*/

// O(1) memory space
void Solution::connect(TreeLinkNode* A) 
{
    TreeLinkNode *first = A, *prev = nullptr, *curr = A, *temp;
    while(first)
    {
        if(!prev)
            curr->next = nullptr;
        else
        {
            curr = first;
            while(curr)
            {
                temp = nullptr;
                while(!temp)
                {
                    if(!prev)
                        break;
                    if(prev->left && prev->left!=curr)
                        temp = prev->left;
                    else if(prev->right && prev->right!=curr)
                    {
                        temp = prev->right;
                        prev = prev->next;
                    }
                    else
                        prev = prev->next;
                }
                curr->next = temp;
                curr = temp;
            }
        }
        prev = first;
        first = nullptr;
        while(!first)
        {
            if(!prev)
                break;
            if(prev->left)
                first = prev->left;
            else if(prev->right)
                first = prev->right;
            else
                prev = prev->next;
        }
    }
}

