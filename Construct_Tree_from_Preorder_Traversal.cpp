/*
Given an array pre[] that represents Preorder traversal of a binary tree. One more array preLN[] is given which has only two possible values ‘L’ and ‘N’. The value ‘L’ in preLN[] indicates that the corresponding node in Binary Tree is a leaf node and value ‘N’ indicates that the corresponding node is non-leaf node.

Input:
There will be T, test cases and for each test case the function will be called separately.
The function takes three arguments as input, first an integer N, denoting the size of both the array, second an array pre[] that represents Preorder traversal of the binary tree and the last argument a character array preLN[] which indicates that the corresponding node in Binary Tree is a leaf node or a normal node.

Output:
The output will be the inorder traversal of the resultant tree.

Constraints:
1 <=T <= 75
1 <= N <= 100
1 <= pre[i] <= 100
preLN[i]: {'N', 'L'}

User Task:
Your task is to complete the function constructTree(), that constructs the tree from the given two arrays and return the root pointer to new binary tree formed.
*/

/*Structure of the Node of the binary tree is as
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return the root of the new binary tree formed
Node* cTree(int n, int pre[], char preLN[], int &i){
    if(i == n)
        return NULL;
        
    Node* root = new Node();
    root->data = pre[i];
    i++;
    
    if(preLN[i - 1] == 'N'){
        root->left = cTree(n, pre, preLN, i);
        root->right = cTree(n, pre, preLN, i);
    }
    
    else{
        root->left = NULL;
        root->right = NULL;
    }
    
    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    if(n == 0)
        return NULL;
    
    Node* root;
    int i;
    i = 0;
    root = cTree(n, pre, preLN, i);
    
    return root;
}