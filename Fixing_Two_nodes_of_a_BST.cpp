/*
Two of the nodes of a Binary Search Tree (BST) are swapped. Fix (or correct) the BST.

Input Format:
First line consists of T test cases. First line of every test case consists of N, denoting number of elements in BST. Second line of every test case consists 3*N elements 2 integers and a character

Note: It is guaranteed than the given input will form BST ,except for 2 nodes that will be wrong.

Output Format:
For each testcase, in a new line, print either 0 or 1.

Your Task:
You don't need to take any input. Just complete the function correctBst() that takes node as parameter. The corrected BST will then be checked internally.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
4
10 5 L 10 8 R  5 2 L 5 20 R
5
8 3 L 8 10 R 3 1 L 3 6 R 6 7 R

Output:
1
0

Explanation:
Testcase 1:

*/


struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};

void swap( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

struct Node* NewNode(int data)
{
    struct Node* Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return(Node);
}
struct Node *correctBST( struct Node* root );
void Inorder(struct Node *root){
	if(root==NULL){
		return;
	}
	Inorder(root->left);
	cout<<root->data<<" ";
	Inorder(root->right);
}
int flag=1;
int c=0;
void inorder(struct Node *temp,struct Node *root){
	if(flag==0){
		return;
	}
	if(temp==NULL&&root==NULL)
		return;
	if(root==NULL){
		flag=0;
		return;
	}
	if(temp==NULL){
		flag=0;
		return;
	}
	if(temp->data==root->data){
	    c++;
	}
	inorder(temp->left,root->left);
	inorder(temp->right,root->right);
}
void insert(struct Node *root,int a1,int a2,char lr){
	if(root==NULL)
		return;
	if(root->data==a1){
		switch(lr){
				case 'L':root->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				break;
			}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

int main()
{   
	int t;
	cin>>t;
	while(t--){
	struct Node *root=NULL;
	struct Node *temp=NULL;
	int n;
	cin>>n;
	int m=n;
	while(n--){
		int a1,a2;
		char lr;
		cin>>a1>>a2>>lr;
		if(root==NULL){
			temp=NewNode(a1);
			root=NewNode(a1);
			switch(lr){
				case 'L':root->left=NewNode(a2);
				        temp->left=NewNode(a2);
				break;
				case 'R':root->right=NewNode(a2);
				        temp->right=NewNode(a2);
				break;
			}
		}
		else{
			insert(root,a1,a2,lr);
			insert(temp,a1,a2,lr);
		}
	}
	flag=1;
	c=0;
	
	root=correctBST(root);

	inorder(temp,root);

	if(c+1==m){
	    cout<<flag<<endl;
	}
	else{
	    cout<<"0\n";
	}
	}
    return 0;
}/*This is a function problem.You only need to complete the function given below*/

/*Complete the function
Node is as follows:
struct Node
{
    int data;
    struct Node *left, *right;
    
    Node(int x){
        int data = x;
        left = right = NULL;
    }
};
*/
void correctBSTNodes(Node* root, Node* &prev, Node* &first, Node* &last, Node* &temp){
    if(root == NULL)
        return;
        
    correctBSTNodes(root->left, prev, first, last, temp);
    
    if(prev != NULL && prev->data > root->data){
        if(first == NULL){
            first = prev;
            temp = root;
        }
        
        else
            last = root;
    }
    prev = root;
    
    correctBSTNodes(root->right, prev, first, last, temp);
}

struct Node *correctBST( struct Node* root )
{
    // add code here.
    if(root == NULL)
        return root;
    
    Node *first, *last, *temp, *prev;
    first = NULL;
    last = NULL;
    temp = NULL;
    prev = NULL;
    
    correctBSTNodes(root, prev, first, last, temp);
    
    if(first != NULL && last != NULL){
        int temp1;
        temp1 = first->data;
        first->data = last->data;
        last->data = temp1;
    }
    
    else if(first != NULL && temp != NULL){
        int temp1;
        temp1 = first->data;
        first->data = temp->data;
        temp->data = temp1;
    }
    
    return root;
}
