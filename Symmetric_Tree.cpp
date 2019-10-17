/*
Given a Binary Tree of size N, your task is to complete the function isSymettric(), that check whether a binary is Symmetric or not, i.e. the binary tree is Mirror image of itself or not.
For example:
The following binary tree is symmetric:

        1
      /   \
    2       2
  /   \   /   \
 3     4 4     3

But the following is not:

       1
     /   \
    2      2
     \      \
      3      3
Input:

The function takes a single argument as input, the root node of the binary tree. There will be T test cases and for each test case the function will be called separately. 
 

Output:
For each testcase the function should return a boolean value.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
3
1 1
1 2 L 1 2 R 0
2 1
10 20 R 10 20 L 20 30 R 5
2 2
10 20 R 10 20 L 10 20 R 10 20 L 20 30 L 100 

Output:
True
False
True

Explanation:
TestCase 1:

             0
           /   \
          1     1
         /       \
        2         2
Tree is mirror image of itself i.e. tree is symmetric

TestCase 2:

             5
          /    \
        10      20
      /    \      \
    20     20      30 
Tree is not mirror image of itself i.e. tree is not symmetric

TestCase 3:

              100
            /     \
          10       10
         /   \    /   \
       20     20 20    20
Tree is mirror image of itself i.e. tree is symmetric


*/

struct Node
{
	int key;
	struct Node* left, *right;
};

Node *newNode(int key)
{
	Node *temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	return (temp);
}

bool isSymmetric(struct Node* root);

void inorder(struct Node *root){
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->key<<' ';
    inorder(root->right);
}

int main()
{
  int t;
  struct Node *child;
  cin>>t;
  while (t--)
  {
     int N1, N2;
     cin>>N1>>N2;
     struct Node *root1 = NULL;
     struct Node *root2 = NULL;
     struct Node *root = NULL;
     map<int, Node*> m;
     while (N1--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root1 == NULL)
             root1 = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     m.clear();
     while (N2--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        cin>>n1>>n2>>lr;
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root2 == NULL)
             root2 = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int N;
     cin>>N;
     root = newNode(N);
     root->left=root1;
     root->right=root2;
     //inorder(root);
     if(isSymmetric(root))cout<<"True"<<endl;
     else cout<<"False"<<endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*
Structure of the node of the tree is as
struct Node
{
	int key;
	struct Node* left, *right;
};
*/
// complete this function
// return true/false if the is Symmetric or not
bool isMirror(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
        
    if(root1 == NULL || root2 == NULL)
        return false;
        
    return root1->key == root2->key && isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
}

bool isSymmetric(struct Node* root)
{
	// Code here
	
	return isMirror(root, root);
}