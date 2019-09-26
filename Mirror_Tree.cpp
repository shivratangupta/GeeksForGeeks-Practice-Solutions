/*
Given a Binary Tree, convert it into its mirror.
MirrorTree1            

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains number of edges. The second line contains relation between nodes.

Output Format:
For each testcase, in a new line, print inorder traversal of mirror tree.

Your Task:
You don't have to take any input. Just complete the function mirror() that takes node as paramter. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

//function Template for C++
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
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
/* Should convert tree to its mirror */
void mirror(Node* node) 
{
     // Your Code Here
     
    if(node == NULL)
        return;
    
    Node* temp;
    temp = node->left;
    node->left = node->right;
    node->right = temp;
    
    mirror(node->left);
    mirror(node->right);
}