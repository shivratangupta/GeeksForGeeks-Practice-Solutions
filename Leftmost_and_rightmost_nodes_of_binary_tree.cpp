/*
Given a Binary Tree, Print the corner nodes at each level. The node at the leftmost and the node at the rightmost.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an intger n denoting the number of edges. The next line contains the edges of the binary tree.

Output:
Print the corner nodes ( nodes at the leftmost and nodes at the rightmost) at each level.

Constraints:
1<=T<=100
1<=data of each node<=100
1<=n<=100

Example:
Input:
2
6
15 10 L 10 8 L 10 12 R 15 20 R 20 16 L 20 25 R
2
1 2 R 2 3 R

Output:
15 10 20 8 25
1 2 3
*/

{
// Your code goes here

    if(root == NULL)
        return;
        
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        int n, a;
        n = q.size();
        a = n;
        
        while(n > 0){
            Node* temp;
            temp = q.front();
            q.pop();
            
            if(n == 1 || n == a)
                cout<<temp->key<<" ";
                
            if(temp->left != NULL)
                q.push(temp->left);
            
            if(temp->right != NULL)
                q.push(temp->right);
                
            n--;
        }
    }
}