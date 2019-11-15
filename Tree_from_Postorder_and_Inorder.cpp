/*
Given inorder and postorder traversals of a Binary Tree in the arrays in[] and post[] respectively. The task is to construct the binary tree from these traversals.

For example, if given inorder and postorder traversals are {4, 8, 2, 5, 1, 6, 3, 7} and {8, 4, 5, 2, 6, 7, 3, 1}  respectively, then your function should construct below tree.

          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes in the tree, and next two lines contains inorder and postorder respectively.

Output Format:
For each testcase, print the preorder traversal of tree.

Your Task:
Complete the function buildTree() which inorder, postorder and number of nodes in the tree, and returns the root of the tree.

Constraints:
1 <= T <= 30
1 <= N <= 103
1 <= in[i], post[i] <= 103

Example:
Input:
2
8
4 8 2 5 1 6 3 7
8 4 5 2 6 7 3 1
5
9 3 2 5 4
5 9 3 4 2

Output:
1 2 4 8 5 3 6 7
2 9 5 4 3

Explanation:
Testcase 1:
          1
       /      \
     2        3
   /    \     /   \
  4     5   6    7
    \
      8
*/

{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// Function should construct tree and return
// root of it.  in[] stores inorder traversal
// post[] stores postorder traversal.  n is
// size of these arrays
Node* constructTree(int in[], int is, int ie, int post[], int ps, int pe){
    if(is > ie)
        return NULL;
        
    else{
        int j;
            
        Node* temp = new Node(post[pe]);
        
        if(is == ie)
            return temp;
            
        for(j=is; j<=ie; j++){
            if(in[j] == temp->data)
                break;
        }
            
        if(j != is)
            temp->left = constructTree(in, is, j-1, post, ps, ps-is+j-1);
            
        if(j != ie)
            temp->right = constructTree(in, j+1, ie, post, ps-is+j, pe-1);
            
        return temp;
    }
}

Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    
    return constructTree(in, 0, n - 1, post, 0, n - 1);
}
