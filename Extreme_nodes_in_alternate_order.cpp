/*
Given a binary tree, print nodes of extreme corners of each level but in alternate order.

Example:


For above tree, the output is

1 2 7 8 31
– print rightmost node of 1st level
– print leftmost node of 2nd level
– print rightmost node of 3rd level
– print leftmost node of 4th level
– print rightmost node of 5th level

 

Input:
The task is to complete the method which takes one argument, root of the Tree. The struct node has a data part which stores the data, pointer to left child and pointer to right child.
There are multiple test cases. For each test case, this method will be called individually.


Output:
The function should print extreme nodes in alternte manner.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000

Example:
Input:
2
2
1 2 R 1 3 L
7
20 8 L 20 22 R 8 4 L 8 12 R 12 10 L 12 14 R 22 25 R

 

Output:
1 3
20 8 25 10

There are two test casess.  First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.   Second test case represents a tree with 7 edges and 8 nodes.
*/

   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
/* Function to print nodes of extreme corners
of each level in alternate order */
void printExtremeNodes(Node* root)
{
    // Your code here
    if(root == NULL)
        return;
        
    queue<Node*> q;
    q.push(root);
    bool flag;
    flag = true;
    
    while(!q.empty()){
        int n , a;
        n = q.size();
        a = n;
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            
            if(flag && n == 1)
                cout<<temp->data<<" ";
                
            if(!flag && n == a)
                cout<<temp->data<<" ";
                
            if(temp->left != NULL)
                q.push(temp->left);
                
            if(temp->right != NULL)
                q.push(temp->right);
                
            n--;
        }
        
        flag = !flag;
    }
}
