/*
Find the level in a binary tree which has the maximum number of nodes. The root is at level 0.

Note: The Input/Output format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.

Input:
The first line consists of T test cases. The first line of every test case consists of N, denoting the number of edges in the tree. The second and third line of every test case consists of N, nodes of the binary tree.

Output:
Print the level number with maximum nodes.

Constraints:
1<=T<=100
1<=N<=100

*/

/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
int maxNodeLevel(Node *root)
{
 // Add your code here
    if(root == NULL)
        return 0;
    
    queue<Node*> q;
    int level, maxnodelevel, maxnode, n;
    level = 0;
    maxnode = 0;
    q.push(root);
    
    while(!q.empty()){
        n = q.size();
        if(n > maxnode){
            maxnode = n;
            maxnodelevel = level;
        }
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            
            if(temp->left != NULL)
                q.push(temp->left);
                
            if(temp->right!= NULL)
                q.push(temp->right);
            
            n--;
        }
        
        level++;
    }
    
    return maxnodelevel;
}