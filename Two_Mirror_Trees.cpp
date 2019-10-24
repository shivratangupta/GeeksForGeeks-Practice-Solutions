/*
Given a Two Binary Trees, write a function that returns true if one is mirror of other, else returns false.


MirrorTree1            

Input:
The task is to complete the method that takes two arguments, roots of two Binary Trees to be checked for mirror.

Output:
The function should return true if first tree is mirror of second.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2 2
1 2 R 1 3 L
1 3 R 1 2 L
4 4
10 20 L 10 30 R 20 40 L 20 60 R
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1
0
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

/* Given two trees, return true if they are
 structurally identical */
int areMirror(Node* a, Node* b);

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> map1, map2;
     int n,m;
     scanf("%d%d",&n,&m);
     struct Node *root1 = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (map1.find(n1) == map1.end())
        {
           parent = newNode(n1);
           map1[n1] = parent;
           if (root1 == NULL)
             root1 = parent;
        }
        else
           parent = map1[n1];

        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        map1[n2]  = child;
     }

     struct Node *root2 = NULL;
     while (m--)
     {
        Node *parent;
        char lr;
        int m1, m2;
        scanf("%d %d %c", &m1, &m2, &lr);

        if (map2.find(m1) == map2.end())
        {
           parent = newNode(m1);
           map2[m1] = parent;
           if (root2 == NULL)
             root2 = parent;
        }
        else
           parent = map2[m1];

        child = newNode(m2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        map2[m2]  = child;
     }


     cout << areMirror(root1, root2) << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */
/* Given two trees, should return true if they are
   mirror of each other. */
int areMirror(Node* a, Node* b)
{
   // Your code here
    if(a == NULL && b == NULL)
        return true;
        
    if(a == NULL || b == NULL)
        return false;
        
    if(a->data != b->data)
        return false;
        
    return areMirror(a->left, b->right) && areMirror(a->right, b->left);
}
