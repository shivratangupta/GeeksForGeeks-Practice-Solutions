/*
Given a Binary Tree, print Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /   \      /    \
  4     5   6    7
    \
     8

Input Format:
The first line of the input contains a single integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line contains number of edges. The second line contains relation between nodes.

Output Format:
For each test case, in a new line, print right view of the binary tree.

Your Task:
This is a function problem. You don't have to take input. Just complete the function rightView() that takes node as parameter and prints the right view. The newline is automatically appended by the driver code.

Constraints:
1 <=T<= 100
1 <= Number of nodes<= 100
1 <= Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
1 2
10 30 60

Explanation:
Test case 1:

           1

        /     \

      3        2

For the above test case the right view is: 1 2

Test case 2:

            10

         /        \

     20          30

   /      \      

40      60

Right View is: 10 30 60.
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */
// Should print right view of tree

void rightViewLevel(Node* root, int level, int &maxlevel){
    if(root == NULL)
        return;
        
    if(maxlevel < level){
        cout<<root->data<<" ";
        maxlevel = level;
    }
    
    rightViewLevel(root->right, level + 1, maxlevel);
    rightViewLevel(root->left, level + 1, maxlevel);
}

void rightView(Node *root)
{
   // Your Code here
   int maxlevel;
   maxlevel = 0;
   
   rightViewLevel(root, 1, maxlevel);
}
