/*
ID: iCoder0020
PROG: Tree : Top View
LANG: C++                  
*/

#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

    void topView(Node * root) 
    {
        queue <pair<Node*, int>>Q;
        map<int, Node*> M;
        M[0] = root;
        Q.push({root,0});
        while(!Q.empty())
        {
            Node* temp = Q.front().first;
            int disp = Q.front().second;
            Q.pop();
            if(temp->left)
            {
                Q.push({temp->left, disp-1});
                if(M.find(disp-1) == M.end())
                {
                    M[disp-1] = temp->left;
                }
            }
            if(temp->right)
            {
                Q.push({temp->right, disp+1});
                if(M.find(disp+1) == M.end())
                {
                    M[disp+1] = temp->right;
                }
            }
        }
        for(auto it: M)
        {
            cout<<it.second->data<<" ";
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
    myTree.topView(root);
    return 0;
}
