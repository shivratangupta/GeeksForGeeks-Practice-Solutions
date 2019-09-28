/*
Consider lines of slope -1 passing between nodes (dotted lines in below diagram). The diagonal sum in a binary tree is the sum of all node’s data lying between these lines. Given a Binary Tree, print all diagonal sums.

DiagonalSum

 

 

 

 

 

 

 

 

 

 

 

 

 

 

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
The first line consists of T test cases. The first line of every test case consists of N, denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.

Output:
Print space separated integers which are the diagonal sums for every diagonal present in the tree with slope -1.
 
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
void diagonalSumMap(Node* root, map<int, int> &m, int x){
    if(root == NULL)
        return;
    
    m[x] += root->data;    
    diagonalSumMap(root->left, m, x + 1);
    diagonalSumMap(root->right, m, x);
}

void diagonalSum(Node* root)
{
 // Add your code here
    if(root == NULL)
        return;
        
    map<int, int> m;
    diagonalSumMap(root, m, 0);
    
    map<int, int> :: iterator it;
    
    for(it = m.begin(); it != m.end(); it++)
        cout<<it->second<<" ";
    
    cout<<endl;
}