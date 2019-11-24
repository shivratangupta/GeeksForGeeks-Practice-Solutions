/*
Given a Binary Search Tree and a target sum, write a function that returns true if there is a pair with sum equals to target sum, otherwise return false.

Input:
First line consists of T test cases. First line of every test case consists of N and target, denoting the number of elements in bst and target sum. Second line consists of elements of BST.

Output:
Return True if target sum pair is found else False.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
7 10
1 2 3 4 5 6 7
7 33
15 10 20 8 12 16 25  
Output:
1
1
*/


/*
struct node
{
    int val;
    struct node *left, *right;
};
*/
bool isPairPresentBST(node* root, int target, unordered_set<int> &s){
    if(root == NULL)
        return false;
        
    if(isPairPresentBST(root->left, target, s))
        return true;
        
    if(s.find(target - root->val) != s.end())
        return true;
        
    else
        s.insert(root->val);
        
    return isPairPresentBST(root->right, target, s);
}

bool isPairPresent(struct node *root, int target)
{
//add code here.
    if(root == NULL)
        return false;
        
    unordered_set<int> s;
    
    return isPairPresentBST(root, target, s);
}