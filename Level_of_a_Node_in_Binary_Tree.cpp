/*
Given a Binary Tree and a target key, your task is to complete the function getLevel() that returns the level of the key from the given binary tree.

           3
         /   \
        2     5
      /   \
     1     4
Key: 4
Level: 3  
Note: if no such key exsits then return 0.
Input:
The function takes 2 arguments as input, first the reference pointer to the root node of the binary tree and a integer value target. There will be multiple test cases and for each test the function will be called seperately.

Output:
For each test return the level of the target value from the binary tree.

Constraints:
1<=T<=100
2<=N<=100

*/

/*
Structure of the node of the binary tree is
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
*/
// function should return level of the target node
int getLevelBT(Node* node, int target, int level){
    if(node == NULL)
        return 0;
        
    if(node->data == target)
        return level;
        
    int newlevel;
    newlevel = getLevelBT(node->left, target, level + 1);
    
    if(newlevel != 0)
        return newlevel;
    
    newlevel = getLevelBT(node->right, target, level + 1);
    
    return newlevel;
}

int getLevel(struct Node *node, int target)
{
	//code here
    
    return getLevelBT(node, target, 1);
}
