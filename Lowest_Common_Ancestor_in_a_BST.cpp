/*
Given a Binary Search Tree and 2 nodes value n1 and n2, your task is to find the lowest common ancestor(LCA) of the two nodes .
Note: Duplicates are not inserted in the BST.

Input Format:
The first line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains three lines of input.
The first line contains N, the number of nodes of the BST.
The second line contains the values of the nodes, each separated by a space.
The third line contains the two values n1 and n2 separated by a space.

Output Format:
For each testcase, in a new line, print the LCA of n1 and n2.

Your Task:
This is a function problem. You don't have to take any input. You are required to complete the function LCA() that takes node, n1, n2 as parameters and returns the node that is LCA of n1 and n2.

Constraints:
1 <= T <= 200
1 <= N <= 100
1 <= Node value <= 1000

Example:
Input
2
6
5 4 6 3 7 8
7 8
6
12 14 15 10 9 8
8 15

Output 
7
12

Explanation 
The BST in above test case will look like

    5
   /  \ 
  4  6
 /      \
3        7
            \ 
             8
here the LCA of 7 and 8 is 7.
*/

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        *tree = new Node(val);
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}


Node* LCA(Node *root, int , int );

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        int l,r;
        cin>>l>>r;

        cout<<LCA(root,l,r)->data<<endl;
    }
}
/*This is a function problem.You only need to complete the function given below*/
/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/
/*You are required to complete
this function*/
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   
    if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);
        
    if(n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);
        
    return root;
}
