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
vector<int>arr;
void inorder(Node* root)
{
    if(!root)
        return;
    inorder(root->left);
    arr.push_back(root->data);
    inorder(root->right);
}
bool checkBST(Node* root) 
{
    inorder(root);
    for(int n = 0; n<arr.size()-1; n++)
    {
        if(arr[n] >= arr[n+1])
            return false;
    }
    return true;
}