/*
Given a simple expression tree, which is also a full binary tree consisting of basic binary operators i.e., + , – ,* and / and some integers, Your task is to evaluate the expression tree.

Input Format:
The first line of input contains an integer T denoting the no of test cases . Then T test cases follow. Each test case contains an integer N denoting the no of nodes. Then in the next line are N space separated values of the nodes of the Binary tree filled in continous way from the left to the right.

Output Format:
For each test case output will be the result obtained by simplifying the expression tree.

Constraints:
1<=T<=100
2<=N<=50

Your Task:
You need to complete the function evalTree which takes the root of the tree as its only argument and returns an integer denoting the result obtained by simplifying the expression tree.

Example(To be used only for expected Output):
Input:
2
7
+ * - 5 4 100 20
3
- 4 7 
*/

/*The structure of node is as follows
struct node{
	string data;
	node *left;
	node *right;
};
*/
/*You are required to complete below method */
int evalTree(node* root)
{
    //Your code here
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return stoi(root->data);
        
    int left, right;
    left = evalTree(root->left);
    right = evalTree(root->right);
    
    if(root->data == "+")
        return left + right;
        
    if(root->data == "-")
        return left - right;
        
    if(root->data == "*")
        return left * right;
        
    return left / right;
}
