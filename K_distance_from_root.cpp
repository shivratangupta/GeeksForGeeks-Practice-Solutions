/*
Given a Binary Tree and a number k. Print all nodes that are at distance k from root (root is considered at distance 0 from itself). Nodes should be printed from left to right. If k is more that height of tree, nothing should be printed.

For example, if below is given tree and k is 2. Output should be 4 5 6.

          1
       /     \
     2        3
   /         /   \
  4        5    6 
     \
      8

Input:
The task is to complete the method which takes two arguments, root of Binary Tree and k. The struct Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should print nodes at k distance from root. Nodes should be printed from left to right.

Constraints:
1 <= T <= 30
1 <= Number of edges<= 100
0 <= k <= height of tree
1 <= data of node <= 1000
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
// function should print the nodes at k distance from root
void printKdistance(Node *root, int k)
{
  // Your code here
    if(root == NULL)
        return;
        
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
    
    printKdistance(root->left, k - 1);
    printKdistance(root->right, k - 1);
}