/*
Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Input:
First line of every test case consists of T test case. First line of every test case consists of N, denoting number of nodes. Second line of every test case consists of 3*N elements denoting , 2 integers and 1 character ,i.e., parent node , child node and character denotes which child.

Output:
Single line output, print the vertical sum from left to right.

Constraints:
1<=T<=100
1<=N<=100
*/

/*Complete the function below
Node is as follows:
struct Node{
int data;
Node *left,*right;
};
*/
void verticalSum(Node* root, map<int, int> &m, int x){
    if(root == NULL)
        return;
    
    m[x] += root->data;
    verticalSum(root->left, m, x - 1);
    verticalSum(root->right, m, x + 1);
}

void printVertical(Node *root)
{
//add code here.
    if(root == NULL)
        return;
        
    map<int, int> m;
    verticalSum(root, m, 0);
    
    map<int, int> :: iterator it;
    
    for(it = m.begin(); it != m.end(); it++)
        cout<<it->second<<" ";
}