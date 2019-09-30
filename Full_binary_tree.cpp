/*
Given a Binary tree, your task is to check whether the Binary tree is a full binary tree or not.

Input:
First line consists of T test case. First line of every test case consists of N, denoting number of Nodes in a binary tree. Second line of every test case consists 3*N elements 2 integers and a character.

Output:
Single line output, return true if it is a full binary tree else false.

Constraints:
1<=T<=100
1<=N<=100
*/

/*Complete the function below
Node is as follows:
struct Node
{
    int key;
    struct Node *left, *right;
};
*/
bool isFullTree (struct Node* root)
{
//add code here.
    if(root == NULL)
        return true;
    
    if(root->left == NULL && root->right == NULL)
        return true;
    
    if(root->left == NULL || root->right == NULL)
        return false;
        
    return isFullTree(root->left) && isFullTree(root->right);
}
