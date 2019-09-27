/*
Given a binary tree, complete the function that returns true if the tree satisfies the following property:
For every node, data value must be equal to the sum of data values in left and right children. Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

Input Format:
The first line consists of T test cases. The first line of every test case consists of N, denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.

Output Format:
Return 1 if the given tree satisfies the given property else return 0.

Your Task:
This is a function problem. You need to only complete the given function isSumProperty() that returns 0 or 1. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 100
*/

/*Complete the function below
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
int isSumProperty(Node *node)
{
 // Add your code here
    if(node == NULL)
        return 1;
    
    if(node->left == NULL && node->right == NULL)
        return 1;
    
    int a, b;
    a = 0;
    b = 0;
    
    if(node->left != NULL)
        a = node->left->data;
    
    if(node->right != NULL)
        b = node->right->data;
        
    if(node->data == a + b && isSumProperty(node->left) && isSumProperty(node->right))
        return 1;
        
    return 0;
    
}