/*
Given below is a tree. The task is to print the Reverse Level Order Traversal of the given tree. You will be given a function reversePrint(), which accepts root of the tree as argument.
                                              
                                           

 

Input:
The first line of input contains T, denoting the number of testcases. Each testcase contains number of edges. The second line contains number of edges+1 data of nodes of tree separated by space.

Output:
For each testcase in new line, print the reverse level order traversal of tree separated by space.

User task:
Since this is a functional problem you don't have to worry about input, you just have to complete the function reversePrint().

Constraints:
1 <= T <= 30
1 <= Number of edges <= 3*103
1 <= Data of a node <= 3*103

Example:
Input:
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 2 1
40 60 20 30 10

Explanation:
Testcase 1: There are total 3 nodes of tree.

Reverse level order traversal of tree is: 3 2 1.
*/


struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
void reversePrint(Node *root)
{
    //Your code here
    if(root == NULL)
        return;
        
    queue<Node*> q;
    stack<Node*> s;
    
    q.push(root);
    
    while(!q.empty()){
        int n;
        n = q.size();
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            s.push(temp);
            
            if(temp->right != NULL)
                q.push(temp->right);
                
            if(temp->left != NULL)
                q.push(temp->left);
                
            n--;
        }
    }
    
    while(!s.empty()){
        Node* temp;
        temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
    }
}