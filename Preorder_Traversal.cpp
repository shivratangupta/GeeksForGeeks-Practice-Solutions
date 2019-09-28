/*
Given a binary tree, print preorder traversal of it. The task is to complete the function preorder(), which accept root of the tree as argument.
For example: preorder traversal of below tree is "1 10 5 39"

        1
     /     \
   10     39
  /
5

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains two lines. The first line contains number of edges in a tree. The second line contains number of edges+1 number of nodes. The struct Node has a data part which stores the data, pointer to left child and pointer to right child.

Output:
The function should print preorder traversal.

User Task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function preorder() that prints the data in preorder way. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 30
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
void preorder(Node* root)
{
  // Your code here
    if(root == NULL)
        return;
  
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}