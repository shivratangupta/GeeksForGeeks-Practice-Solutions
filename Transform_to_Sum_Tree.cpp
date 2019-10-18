/*
Given a Binary Tree where each node has positive and negative values. Convert this to a tree where each node contains the sum of the left and right sub trees in the original tree. The values of leaf nodes are changed to 0.

For example, the following tree

             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5

should be changed to

       20(4-2+12+6)
          /              \
     4(8-4)      12(7+5)
       /   \           /  \
     0      0       0    0

 

Input:

The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function convert the passed tree to its sum tree.  

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
3 1 L 3 2 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:

0 3 0
0 100 0 150 0

The output in this sample test case is Inorder traversal of modified tree.

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 3, left child of 3 is 1 and right child of 3 is 2.   Second test case represents a tree with 4 edges and 5 nodes.
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

void toSumTree(struct Node *node);

// A utility function to print inorder traversal of a Binary Tree
void printInorder(struct Node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);
     printInorder(node->right);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}


/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
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
     toSumTree(root);
     printInorder(root);
     printf("\n");
  }
  return 0;
}

/* Utillity function to check if the given node is leaf or not */
int isLeaf(struct Node *node)
{
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return 0;
}

/* returns 1 if SumTree property holds for the given
    tree */
bool isSumTree(struct Node* node)
{
    int ls; // for sum of nodes in left subtree
    int rs; // for sum of nodes in right subtree

    /* If node is NULL or it's a leaf node then
       return true */
    if(node == NULL || isLeaf(node))
        return 1;

    if( isSumTree(node->left) && isSumTree(node->right))
    {
        // Get the sum of nodes in left subtree
        if(node->left == NULL)
            ls = 0;
        else if(isLeaf(node->left))
            ls = node->left->data;
        else
            ls = 2*(node->left->data);

        // Get the sum of nodes in right subtree
        if(node->right == NULL)
            rs = 0;
        else if(isLeaf(node->right))
            rs = node->right->data;
        else
            rs = 2*(node->right->data);

        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return(node->data == ls + rs);
    }

    return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Convert a given tree to a tree where every node contains sum of values of
// nodes in left and right subtrees in the original tree
int sumTree(Node* root){
    if(root == NULL)
        return 0;
        
    if(root->left == NULL && root->right == NULL){
        int temp;
        temp = root->data;
        root->data = 0;
        return temp;
    }
    
    int left, right, temp;
    left = sumTree(root->left);
    right = sumTree(root->right);
    
    temp = root->data;
    root->data = left + right;
    
    return left + right + temp;
}

void toSumTree(Node *node)
{
    // Your code here
    sumTree(node);
}
