/*
Given a binary tree, find height of it.

        1
     /     \
   10      39
  /
5
The above tree has a height of 3.
Note: Height of empty tree is considered 0.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains two lines of input. The first line contains number of edges. The second line contains relation between nodes.

Output Format:
For each testcase, in a new line, print the height of tree.

Your Task:
You don't have to take input. Complete the function height() that takes node as parameter and returns the height. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/

/* Tree node structure  used in the program
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
/* Computes the height of binary tree with given root.  */
int height(Node* node)
{
   // Your code here
    if(node == NULL)
        return 0;
        
    return 1 + max(height(node->left), height(node->right));
}
