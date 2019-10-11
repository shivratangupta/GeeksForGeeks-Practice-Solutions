/*
Given a a Binary Tree, your task is to complete the function getLevelDiff which  returns the difference between the sum of nodes at odd level and the sum of nodes at even level . The function getLevelDiff  takes only one argument  ie the root of the binary tree . 

       2
     /    \
    3     5
For the above tree the odd level sum is 2 and even level sum is 8 thus the difference is 2-8=-6

Input:
The task is to complete the method which takes one argument, root of Binary Tree. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return an integer denoting the difference between the sum of nodes at odd level and the sum of nodes at even level

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 20
*/

/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*You are required to complete this function*/
int getLevelDiff(Node *root)
{
   //Your code here
   
    if(root == NULL)
        return 0;
        
    queue<Node*> q;
    int evensum, oddsum, n, level;
    evensum = 0;
    oddsum = 0;
    level = 1;
    q.push(root);
    
    while(!q.empty()){
        n = q.size();
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            
            if(level % 2 == 0)
                evensum += temp->data;
                
            else
                oddsum += temp->data;
                
            if(temp->left != NULL)
                q.push(temp->left);
                
            if(temp->right != NULL)
                q.push(temp->right);
                
            n--;
        }
        
        level++;
    }
    
    return oddsum - evensum;
}
