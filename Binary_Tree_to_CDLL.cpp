/*
Given a Binary Tree of N edges. The task is to convert this to a Circular Doubly Linked List(CDLL) in-place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted CDLL. The order of nodes in CDLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (left most node in BT) must be head node of the CDLL.

Input Format:
First line of input contains number of testcases T. For each testcase, there will be two lines, first of which containing the number of edges (between two nodes) in the tree. Next line contains N pairs (considering a and b) with a 'L' (means node b on left of a) or 'R' (means node b on right of a) after a and b

Output Format:
For each testcase, in a new line, print the traversals of CDLL.

Your Task:
You don't have to take input. Complete the function bTreeToCList() that takes root as parameter and returns the head of the list. The printing is done by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 103
1 <= Data of a node <= 104
*/

/*Complete the function below
Node is as follows:
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
Node* concatenate(Node* left, Node* right){
    if(left == NULL)
        return right;
        
    if(right == NULL)
        return left;
        
    Node *leftend, *rightend;
    leftend = left->left;
    rightend = right->left;
    
    leftend->right = right;
    right->left = leftend;
    
    left->left = rightend;
    rightend->right = left;
    
    return left;
}

Node *bTreeToCList(Node *root)
{
//add code here.
    if(root == NULL)
        return NULL;
        
    Node *left, *right;
    
    left = bTreeToCList(root->left);
    right = bTreeToCList(root->right);
    
    root->left = root;
    root->right = root;
    
    return concatenate(concatenate(left, root), right);
}