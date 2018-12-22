/*
ID: iCoder0020
PROG: Tree: Height of a Binary Tree
LANG: C++                  
*/

#include <bits/stdc++.h>

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
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) 
    {
        if(root->left==NULL && root->right == NULL)
        {
            return 0;
        }
        else
        {
            int h_left = 0;
            int h_right = 0;
            if(root->left != NULL)
            {
                h_left = 1 + height(root->left);
            }
            if(root->right != NULL)
            {
                h_right = 1 + height(root->right);
            }
            return max(h_left, h_right);
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
  
    int height = myTree.height(root);
    
    std::cout << height;

    return 0;
}
