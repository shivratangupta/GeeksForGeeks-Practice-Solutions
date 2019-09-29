/*
Given a Binary Tree having positive and negative nodes, the task is to find maximum sum level in it.

Examples:

Input :               4
                    /   \
                   2    -5
                  / \    /\
                -1   3 -2  6
Output: 6
Explanation :
Sum of all nodes of 0'th level is 4
Sum of all nodes of 1'th level is -3
Sum of all nodes of 0'th level is 6
Hence maximum sum is 6

Input :          1
               /   \
             2      3
           /  \      \
          4    5      8
                    /   \
                   6     7  
Output :  17
 
Input:
The task is to complete the method which takes one argument, root of Binary Tree. The Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output:
The function should return max sum level in the tree.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
-1000 <=Data of a node<= 1000
*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */
int maxLevelSum(Node * root)
{
   //Your code here
    if(root == NULL)
        return 0;
    
    int maxsum;    
    queue<Node*> q;
    q.push(root);
    maxsum = 0;
    
    while(!q.empty()){
        int sum, n;
        n = q.size();
        sum = 0;
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            sum += temp->data;
            
            if(temp->left != NULL)
                q.push(temp->left);
                
            if(temp->right != NULL)
                q.push(temp->right);
                
            n--;
        }
        
        if(sum > maxsum)
            maxsum = sum;
    }
    
    return maxsum;
}
