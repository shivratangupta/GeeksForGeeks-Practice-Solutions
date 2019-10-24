/*
Given a binary tree, your task is to complete the function binaryTreeToBST which converts the binary tree to binary search tree(BST) and returns the root of the converted binary search tree.
Note : The conversion must be done in such a way that keeps the original structure of Binary Tree.

          1
       /    \
     2       3
   /        
4       

For the tree above the converted tree will be

        3
      /   \
    2     4
  /
1

Input:

The task is to complete the method which takes one argument, root of Binary Tree and returns the root of the new converted binary search tree.There are multiple test cases. For each test case, this method will be called individually.

Output:
The output will be the inorder traversal of the the converted  binary search tree .

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20
 

Example(To be used only for expected output):
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 2 3
10 20 30 40 60


There are two test cases.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 4 edges and 5 nodes.


*/

{
    int data;
    Node* left;
    Node* right;
}; */
/*Your code here*/
void storeArrayInorder(Node* root, vector<int> &arr){
    if(root == NULL)
        return;
        
    storeArrayInorder(root->left, arr);
    arr.push_back(root->data);
    storeArrayInorder(root->right, arr);
}

void inorderBST(Node* root, vector<int> &arr, int &i){
    if(root == NULL)
        return;
        
    inorderBST(root->left, arr, i);
    
    root->data = arr[i];
    i++;
    
    inorderBST(root->right, arr, i);
}

Node *binaryTreeToBST (Node *root)
{
//Your code here 
    if(root == NULL)
        return root;
        
    vector<int> arr;
    
    storeArrayInorder(root, arr);
    
    sort(arr.begin(), arr.end());
    
    int i;
    i = 0;
    
    inorderBST(root, arr, i);
    
    return root;
}
 