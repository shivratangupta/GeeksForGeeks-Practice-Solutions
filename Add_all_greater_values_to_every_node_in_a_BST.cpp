/*
Given a Binary Search Tree (BST), modify it so that all greater values in the given BST are added to every node.
In this function problem, the task is to complete the function modify which takes one argument: Address of the root of the BST. The function should contain the logic to modify the BST so that in the modified BST, every node has a value equal to the sum of its value in the original BST and  values of all the elements larger than it in the original BST.

The BST node structure has 3 fields, a data part which stores the data, a left pointer which points to the left element of the BST and a right pointer which points to the right node of the BST. 

There are multiple test cases. For each test case, this function will be called individually.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow. Each test case consists of two lines. First line of each test case contains an integer N denoting the no of nodes of the BST . Second line of each test case consists of 'N' space separated integers denoting the elements of the BST. These elements are inserted into BST in the given order.

Output:
Print the inorder traversal of the modified BST.

Expected Time Complexity: O(N)

Constraints:
1<=T<=100
1<=N<=200

Example:
Input:
1
7
50 30 20 40 70 60 80     (Elements are inserted into BST in this order only)

Output:
350 330 300 260 210 150 80         (Inorder Traversal of the modified BST)

Explanation:

              50
           /      \
         30        70
        /   \      /  \
      20    40    60   80 

The above tree should be modified to following 

              260
           /      \
         330        150
        /   \       /  \
      350   300    210   80
*/

struct Node {
int data;
struct Node * right, * left;
};
void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = (Node *)malloc(sizeof(Node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
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
void inorderrrrr(Node *root)
{
    if(root!=NULL)
    {
    inorderrrrr(root->left);
    cout<<root->data<< " ";
    inorderrrrr(root->right);
    }
}
void modify(Node **root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;
        root = NULL;
        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);
        }
        modify(&root);
        inorderrrrr(root);
        cout<<endl;
    }
}/*This is a function problem.You only need to complete the function given below*/
/* BST Node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*  modifies the root of the bst */
Node* modifyBST(Node *root, int &sum){
    if(root == NULL)
        return root;
        
    root->right = modifyBST(root->right, sum);
    
    sum += root->data;
    root->data = sum;
    
    root->left = modifyBST(root->left, sum);
}

void modify(Node **root)
{
// Your code here
    int sum;
    sum = 0;
    
    *root = modifyBST(*root, sum);
}