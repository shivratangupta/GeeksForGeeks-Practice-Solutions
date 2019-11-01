/*
Given two BST, you need to print the elements of both BSTs in sorted form.

Input Format:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains three lines. The first line of each test case contain's an integer N and M denoting the size of the two BST's. Then In the next two line are space separated values of the two BST's.

Output Format:
For each testcase, in a new line, print the elements of both BSTs in sorted form.

Your Task:
This is a function problem, you don't have to take any input. Just complete the function merge() that nodes of both BSTs as parameters.

Constraints:
1 <= T <= 100
1 <= N,M <= 100

Example:
Input:
2
3 3
1 33 4 
6 7 1
2 2
1 6
9 2

Output:
1 1 4 6 7 33
1 2 6 9

Explanation:
Testcase1: The BSTs look like

BST1:
                1
                  \
                    4
                       \
                         33

BST2:
                     6
                    /   \
                   1    7
The sorted elements of above BSTs are 1 1 4 6 7 33
*/

/*
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};*/
/*You are required to complete below method */
void inorder(Node* root){
    if(root == NULL)
        return;
        
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void merge(Node *root1, Node *root2)
{
   //Your code here
    stack<Node*> s1;
    stack<Node*> s2;
    
    Node *curr1, *curr2;
    curr1 = root1;
    curr2 = root2;
    
    if(root1 == NULL){
        inorder(root2);
        return;
    }
    
    if(root2 == NULL){
        inorder(root1);
        return;
    }
    
    while(curr1 != NULL || curr2 != NULL || !s1.empty() || !s2.empty()){
        if(curr1 != NULL || curr2 != NULL){
            if(curr1 != NULL){
                s1.push(curr1);
                curr1 = curr1->left;
            }
            
            if(curr2 != NULL){
                s2.push(curr2);
                curr2 = curr2->left;
            }
        }
        
        else{
            if(s1.empty()){
                while(!s2.empty()){
                    curr2 = s2.top();
                    s2.pop();
                    curr2->left = NULL;
                    inorder(curr2);
                }
                
                return;
            }
            
            if(s2.empty()){
                while(!s1.empty()){
                    curr1 = s1.top();
                    s1.pop();
                    curr1->left = NULL;
                    inorder(curr1);
                }
                
                return;
            }
            
            curr1 = s1.top();
            curr2 = s2.top();
            s1.pop();
            s2.pop();
            
            if(curr1->data < curr2->data){
                cout<<curr1->data<<" ";
                curr1 = curr1->right;
                s2.push(curr2);
                curr2 = NULL;
            }
            
            else{
                cout<<curr2->data<<" ";
                curr2 = curr2->right;
                s1.push(curr1);
                curr1 = NULL;
            }
        }
    }
}