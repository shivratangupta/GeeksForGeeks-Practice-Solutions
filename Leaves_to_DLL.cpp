/*
Given a Binary Tree with N edges. The task is to extract all leaves of it in a Doubly Linked List (DLL). Note that the DLL need to be created in-place. Assume that the node structure of DLL and Binary Tree is same, only the meaning of left and right pointers are different. In DLL, left means previous pointer and right means next pointer. Head of DLL should point to the left most leaf and then in inorder traversal and so on.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which containing the number of edges (between two nodes) in the tree. Next line contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b.

Output:
For each testcase, there will be two lines containing the nodes of DLL, first in reverse order and next in order of inorder traversal of tree.

User Task:
The task is to complete the function convertToDLL() which converts given binary tree to DLL.

Constraints:
1 <= T <= 100
1 <= N <= 103
*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
Node *convertToDLL(Node *root,Node **head_ref)
{
//add code here.

    if(root == NULL)
        return NULL;
    
    if(root->left == NULL && root->right == NULL){
        root->right = *head_ref;
        
        if(*head_ref != NULL)
            (*head_ref)->left = root;
        
        *head_ref = root;
        
        return NULL;
    }
    
    root->right = convertToDLL(root->right, head_ref);
    root->left = convertToDLL(root->left, head_ref);
    
    return root;
}