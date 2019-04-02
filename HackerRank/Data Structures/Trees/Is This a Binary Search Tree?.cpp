/*
ID: iCoder0020
PROG: Is This a Binary Search Tree?
LANG: C++                  
*/

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
    struct Node {
        int data;
        Node* left;
        Node* right;
    }
*/

int prev = -1;
int curr;
bool asc = true;

void inorder(Node* root)
{
    if(root && asc)
    {
        inorder(root->left);
        curr = root->data;
        if(curr <= prev)
            asc = false;
        prev = curr;
        inorder(root->right);
    }
}
bool checkBST(Node* root) 
{
    inorder(root);
    if(asc)
        return true;
    return false;
}