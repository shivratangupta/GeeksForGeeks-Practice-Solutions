/*
You are given a tree and you need to do the level order traversal on this tree.
Level order traversal of a tree is breadth-first traversal for the tree.



Level order traversal of above tree is 1 2 3 4 5

Input Format:
The task is to complete the method which takes one argument, root of Binary Tree. The struct Node has a data part which stores the data, pointer to left child and pointer to the right child.
There are multiple test cases. For each test case, this method will be called individually.

Output Format:
The function should print the level order traversal of the tree as specified in the problem statement.

Your Task:
You don't have to take any input. Just complete the function levelOrder() that takes node as parameter and prints the level order. The newline is automatically appended by the driver code.

Constraints:
1 <= T <= 100
1 <= Number of edges <= 1000
1 <= Data of a node <= 100

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R
Output:
1 3 2
10 20 30 40 60

Explanation:
Testcase1: The tree is
        1
     /      \
   3       2
So, the level order would be 1 3 2
Testcase2: The tree is
                           10
                        /        \
                     20         30
                  /       \
               40       60
So, the level order would be 10 20 30 40 60
*/

void levelOrder(struct Node* node);

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

void levelOrder(struct Node* node);

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;

  inOrder(node->left);
  printf("%d ", node->data);

  inOrder(node->right);
}


/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *node = NULL;
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
           if (node == NULL)
             node = parent;
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

     levelOrder(node);
     cout << endl;
  }
  return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree Node
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
//You are required to complete this method
void levelOrder(Node* node)
{
  //Your code here
    if(node == NULL)
        return;
        
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty()){
        int n;
        n = q.size();
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            
            cout<<temp->data<<" ";
            
            if(temp->left != NULL)
                q.push(temp->left);
                
            if(temp->right != NULL)
                q.push(temp->right);
                
            n--;
        }
    }
}
