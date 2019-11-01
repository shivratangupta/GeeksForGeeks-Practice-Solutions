/*
Given a Binary Search Tree (BST) and a range, print all the numbers in the BST that lie in the given range l-h(inclusive) in non-decreasing order. If no such element exists, an empty line will be printed.
Note: Element greater than or equal to root go to the right side.

Input Format:
The first line of the input contains an integer 'T' denoting the nummber of test cases. Then 'T' test cases follow. Each test case consists of three lines. Description of  test cases is as follows:
The First line of each test case contains an integer 'N' which denotes the number of nodes in the BST.   .
The Second line of each test case contains 'N' space separated values of the nodes in the BST.
The Third line of each test case contains two space separated integers 'l' and 'h' denoting the range.

Output Format:
For each testcase, in a new line, print print all the numbers in the BST that lie in the given range in non-decreasing order.

Your Task:
This is a function problem. You don't have to take any input. Complete the function printNearNodes() that takes root, l, h as parameters and prints numbers in the BST that lie in the given range in non-decreasing order.

Constraints:
1 <= T <= 100
1 <= N <= 50
1 <= l < h < 1000

Example:
Input:
2
6
10 5 50 1 40 100
5 45
4
5 6 3 2
1 4

Output:
5 10 40
2 3

Explanation:
Testcase 1: Elements which are in the range of 5 and 45(inclusive) are 5 10 40.
*/


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

Node *insert(Node *root,int data)
{
    if(root==NULL)
    root=new Node(data);
    else if(data<root->data)
    root->left=insert(root->left,data);
    else
    root->right=insert(root->right,data);
    
    return root;
}


/*This is a function problem.You only need to complete the function given below*/
/* The structure of a BST Node is as follows:
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
void printNearNodes(Node *root, int l, int h)
{
  // your code goes here
    if(root == NULL)
        return;
        
    printNearNodes(root->left, l, h);
    
    if(root->data >= l && root->data <= h)
        cout<<root->data<<" ";
        
    printNearNodes(root->right, l, h);
}



int main() {
    
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        Node *root=NULL;
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray;i++)
        cin>>arr[i];
        
        for(int i=0;i<sizeOfArray;i++)
        {
            root=insert(root,arr[i]);
        }
        int l,h;
        cin>>l>>h;
        printNearNodes(root,l,h);
        cout<<endl;

    }
	return 0;
}
