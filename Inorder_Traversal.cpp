/*
Given a binary tree, the task is to print the nodes in inorder traversal of it. Inorder traversal of below tree is 5 10 1 39

        1
     /      \
   10      39
  /
5

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains number of edges in the tree. For each edge there will be three consecutive inputs, first two integers contains parent node and child node, and the last character defines whether the child is in left or right.

Output Format:
For each testcase, in a new line, print the inorder traversal.

Your Task:
This is a function problem. You just need to complete the function inorder() that takes node as parameter. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
void inOrder(Node* root)
{
  // Your code here
    if(root == NULL)
        return;
        
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
