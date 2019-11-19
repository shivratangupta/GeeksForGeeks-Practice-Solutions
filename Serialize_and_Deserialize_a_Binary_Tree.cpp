/*
Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to tree and returns it.
Note: The structure of tree must be maintained.

Input Format:
 The method serialize takes  two arguments, the first is the root of Binary Tree and second argument is an array A[ ] which stores the serialized tree. The method deSerialize takes only one argument which is the serialized array A[] and returns the deserialzed tree's root . The struct Node has a data part which stores the data, pointer to left child and pointer to right child.There are multiple test cases. For each test case, this method will be called individually.

Output Format:
The  output in the expected output will be the inorder traversal of the returned tree .

Your Task:
The task is to complete two method serialize and deSerialize.

Constraints:
1 <=T<= 30
1 <= Number of nodes<= 100
1 <= Data of a node<= 100

Example(To be used only for expected output):
Input
2
2
1 2 L 1 3 R
4
10 20 L 10 30 R 20 40 L 20 60 R

Output
2 1 3
40 20 60 10 30
*/

struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
/*this  function serializes 
the binary tree and stores 
it in the vector A*/
void serialize(Node *root,vector<int> &A)
{
    //Your code here 
    if(root == NULL){
        A.push_back(-1);
        return;
    }
        
    A.push_back(root->data);
    serialize(root->left, A);
    serialize(root->right, A);
}
/*this function deserializes
 the serialized vector A*/
 
Node* deSerializeArray(vector<int> &A, int &i){
    if(i == A.size() || A[i] == -1){
        i++;
        return NULL;
    }
    
    Node* root = new Node;
    root->data = A[i];
    i++;
    root->left = deSerializeArray(A, i);
    root->right = deSerializeArray(A, i);
    
    return root;
}

Node * deSerialize(vector<int> &A)
{
   //Your code here
   int i;
   i = 0;
   
   return deSerializeArray(A, i);
}