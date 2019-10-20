/*
Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

A height balanced tree
        1
     /     \
   10      39
  /
5

An unbalanced tree
        1
     /    
   10   
  /
5

Input Format:
The input contains T, denoting number of testcases. For each testcase there will be two lines. The first line contains number of edges. The second line contains two nodes and a character separated by space. The first node denotes data value, second node denotes where it will be assigned to the previous node which will depend on character 'L' or 'R' i.e. the 2nd node will be assigned as left child to the 1st node if character is 'L' and so on. The first node of second line is root node. The struct or class Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, the function will be called individually.

Output Format:
For each testcase, in a new line, print 0 or 1 accordingly.

Your Task:
You don't need to take input. Just complete the function isBalanced() that takes root node as parameter and returns true, if the tree is balanced else returns false.

Constraints:
1 <= T <= 100
1 <= Number of nodes <= 100
0 <= Data of a node <= 1000

Example:
Input:
2
2
1 2 L 2 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
0
1
Explanation:
Testcase1: The tree is
        1
     /    
   2
      \
       3 
The max difference in height of left subtree and right subtree is 2, which is greater than 1. Hence unbalanced.
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
The max difference in height of left subtree and right subtree is 1. Hence unbalanced.
*/


/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

bool isBalanced(struct Node *root);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */


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
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isBalanced(root) << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node structure
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should return tree if passed  tree 
// is balanced, else false.
int height(Node* root){
    if(root == NULL)
        return 0;
        
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node *root)
{
    //  Your Code here
    
    if(root == NULL)
        return true;
        
    int lh, rh;
    lh = height(root->left);
    rh = height(root->right);
    
    if(abs(lh - rh) > 1)
        return false;
        
    return isBalanced(root->left) && isBalanced(root->right);
}
