/*
Given a Binary Tree having random pointers clone the Binary Tree. The task is to complete the function cloneTree which take one argument the root of the tree to be copied and should return the root of the cloned tree.

Input:
The first line of input contains the no of test cases. Then T test cases follow. Each test case contains 2 lines the first line contains and integer N denoting the no of edges of the tree and then in the next line are N space separated queries .The query on tree are of three types
a) a b L  (Represents that b is the left child of a)
b) a b R (Represents that b is the right child of a)
c) a b X (Represents a random pointer from node a to node b)  

Output:
Your function should return the root of the cloned tree. The output will be 1 if the tree is successfully cloned.

Constraints:
1 <=T<= 30
1 <=Number of nodes<= 100
1 <=Data of a node<= 1000
*/

/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node *random;
};
*/
/* The function should clone the passed tree and return 
   root of the cloned tree */
Node* copyTreeNode(Node* tree, unordered_map<Node*, Node*> &m){
    if(tree == NULL)
        return NULL;
        
    Node* temp = new Node();
    temp->data = tree->data;
    m[tree] = temp;
    temp->left = copyTreeNode(tree->left, m);
    temp->right = copyTreeNode(tree->right, m);
    
    return temp;
}

void setRandom(Node* tree, Node* copytree, unordered_map<Node*, Node*> &m){
    if(tree == NULL)
        return;
    
    copytree->random = m[tree->random];
    setRandom(tree->left, copytree->left, m);
    setRandom(tree->right, copytree->right, m);
}

Node* cloneTree(Node* tree)
{
   //Your code here
    if(tree == NULL)
        return NULL;
        
    unordered_map<Node*, Node*> m;
    Node* copytree;
    copytree = copyTreeNode(tree, m);
    setRandom(tree, copytree, m);
    
    return copytree;
}
