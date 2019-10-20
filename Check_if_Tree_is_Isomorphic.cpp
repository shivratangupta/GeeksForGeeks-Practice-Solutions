/*
Write a function to detect if two trees are isomorphic. Two trees are called isomorphic if one of them can be obtained from other by a series of flips, i.e. by swapping left and right children of a number of nodes. Any number of nodes at any level can have their children swapped. Two empty trees are isomorphic.

Input:
First line consists of T test cases. First line of every test case consists of N, denoting number of Node in tree. Second and third line of every test case consists of N, nodes of binary tree.

Output:
Single line output, return the boolean value true if "Yes" else "No".

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
2
3
1 2 L 1 3 R 2 4 L
1 3 L 1 2 R 3 4 R
3
1 2 L 1 3 R 2 4 L
1 3 L 1 2 R 2 4 R
Output:
No
Yes
*/

	int data;
	Node *left,*right;
};
Node *newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return (temp);
}
void insert(Node *root,int a1,int a2,char lr){
	if(root==NULL){
		return;
	}
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
			break;
			case 'R':root->right=newNode(a2);
			break;
		}
	}
	else{
		insert(root->left,a1,a2,lr);
		insert(root->right,a1,a2,lr);
	}
}
void inorder(Node *root){
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
bool isIsomorphic(Node *root1,Node *root2);
int main(){
		int t;
		cin>>t;
		while(t-->0){
			int n;
			cin>>n;
			int m=n;
			Node *root1=NULL;
			Node *root2=NULL;
			while(n-->0){
				int a1,a2;
				cin>>a1>>a2;
				char lr;
				scanf(" %c",&lr);
				if(root1==NULL){
					root1=newNode(a1);
					switch(lr){
						case 'L':root1->left=newNode(a2);
						break;
						case 'R':root1->right=newNode(a2);
						break;
					}
				}
				else{
					insert(root1,a1,a2,lr);
				}
			}
			while(m-->0){
				int a1,a2;
				cin>>a1>>a2;
				char lr;
				scanf(" %c",&lr);
				if(root2==NULL){
					root2=newNode(a1);
					switch(lr){
						case 'L':root2->left=newNode(a2);
						break;
						case 'R':root2->right=newNode(a2);
						break;
					}
				}
				else{
					insert(root2,a1,a2,lr);
				}
			}
			/*inorder(root1);
			cout<<endl;
			inorder(root2);*/
			if(isIsomorphic(root1,root2)){
				cout<<"Yes\n";
			}
			else{
				cout<<"No\n";
			}
		}
	}/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below
Node is as follows:
struct Node{
	int data;
	Node *left,*right;
};
*/
bool isIsomorphic(Node *root1,Node *root2)
{
//add code here.

    if(root1 == NULL && root2 == NULL)
        return true;
        
    if(root1 == NULL || root2 == NULL)
        return false;
        
    if(root1->data != root2->data)
        return false;
        
    return isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right) ||
            isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);
}