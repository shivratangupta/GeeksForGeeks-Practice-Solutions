/*
Given root of binary search tree and K as input, find K-th smallest element in BST. Your task is to return the K-th smallest element in BST from the function k_smallest_element().

Note: The Time Complexity will be O(h) where h is the height of the Tree.

Input:
The first line of input will contain the number of test cases T. Then T test cases follow. First line of every test case will be n, denoting the number of nodes in the BST. Second line of every test case will be n spaced integers denoting the Integer value of Nodes in BST. Third line of every test case will be k, denoting kth the smallest number.

Output:
For each test case, output will be the kth smallest element of BST.

Constraints:
1<=T<=100
1<=N<=100
1<=K<=N


Example(To be used only for expected output):
Input:
1
5
20 8 4 22 12
3 
Output:
12
*/

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
typedef struct Node Node;

struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};
int KthSmallestElement(Node *root, int k);

Node *insert_node(Node *root, Node* node)
{
    Node *pTraverse = root;
    Node *currentParent = root;
 
    while(pTraverse)
    {
        currentParent = pTraverse;
 
        if( node->data < pTraverse->data )
        {
            pTraverse->lCount++;
            pTraverse = pTraverse->left;
        }
        else
        {
            pTraverse = pTraverse->right;
        }
    }
    if( !root )
    {
        root = node;
    }
    else if( node->data < currentParent->data )
    {
        currentParent->left = node;
    }
    else
    {
        currentParent->right = node;
    }
 
    return root;
}

Node* binary_search_tree(Node *root, int keys[], int const size)
{
    int iterator;
    Node *new_node = NULL;
 
    for(iterator = 0; iterator < size; iterator++)
    {
        new_node = (Node *)malloc( sizeof(Node) );
 
        /* initialize */
        new_node->data   = keys[iterator];
        new_node->lCount = 0;
        new_node->left   = NULL;
        new_node->right  = NULL;
 
        /* insert into BST */
        root = insert_node(root, new_node);
    }
 
    return root;
}
 
 int main(void)
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
    int ele[n];
	for(int i=0;i<n;i++){
		cin>>ele[i];
	}
    int k;
	cin>>k;
    Node* root = NULL;
    root = binary_search_tree(root, ele, ARRAY_SIZE(ele));
        printf("%d\n",KthSmallestElement(root, k));
	}
    return 0;
}/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};*/
int count(Node* root){
    if(root == NULL)
        return 0;
        
    return 1 + count(root->left) + count(root->right);
}

int KthSmallestElement(Node *root, int k)
{
    //add code here.
    if(root == NULL)
        return 0;
        
    int n;
    n = count(root->left);
    
    if(k == n + 1)
        return root->data;
        
    if(k <= n)
        return KthSmallestElement(root->left, k);
        
    else
        return KthSmallestElement(root->right, k - n - 1);
}