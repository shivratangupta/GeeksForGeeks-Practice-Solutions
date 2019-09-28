/*
Given a binary tree, where every node value is a number. Find the sum of all the numbers which are formed from root to leaf paths.

For example consider the following Binary Tree.
 

           6                               
         /   \                          
        3     5                      
      /   \     \
     2    5      4             
        /  \                        
       7    4                 
            
  There are 4 leaves, hence 4 root to leaf paths:
  Path                      Number
  6->3->2                   600+30+2=632
  6->3->5->7                6000+300+50+7=6357
  6->3->5->4                6000+300+50+4=6354
  6->5>4                    600+50+4=654   
Answer = 632 + 6357 + 6354 + 654 = 13997 
Input Format:
The task is to complete the method which takes one argument, root of Binary Tree. The Node has a data part which stores the data, pointer to left child and pointer to right child. There are multiple test cases. For each test case, this method will be called individually.

Output Format:
The function should return sum of all the numbers which are formed from root to leaf paths.

Your Task:
Don't take any input/output. Just complete the function treePathsSum.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000
*/

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */
/*You are required to complete below method */
void rootToLeafPathSum(Node* root, long long sum, long long &totalsum){
    if(root == NULL)
        return;
        
    sum = sum * 10 + root->data;
    
    if(root->left == NULL && root->right == NULL){
        totalsum += sum;
        return;
    }
    
    rootToLeafPathSum(root->left, sum, totalsum);
    rootToLeafPathSum(root->right, sum, totalsum);
}

long long treePathsSum(Node *root)
{
    //Your code here
    long long sum, totalsum;
    sum = 0;
    totalsum = 0;
    
    rootToLeafPathSum(root, sum, totalsum);
    
    return totalsum;
}
