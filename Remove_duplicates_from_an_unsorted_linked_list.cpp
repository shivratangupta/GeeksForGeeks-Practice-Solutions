/*
Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted Linked List. If all the nodes in the linked list are equal, then remove n-1 nodes.

Input:
First line of input contains number of testcases T. For each testcases, first line of input contains number of nodes in the linked list, and next line contains node data for N nodes.

Output:
For each testcase, print the linked list with no repeating elements.

User Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the  linked list  .You should not read any input from stdin/console. Your function should return a pointer to a linked list with no duplicate element.

Constraints:
1 <= T <= 100
1 <= size of linked lists <= 50

Example:
Input:
2
4
5 2 2 4
5
2 2 2 2 2

Output:
5 2 4
2

Explanation:
Testcase 1: Given linked list elements are 5->2->2->4, in which 2 is repeated only. So, we will delete the extra repeated elements 2 from the linked list and the resultant linked list will contain 5->2->4.
*/


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

Node* removeDuplicates(Node *root);

int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
	
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
		
	}
	return 0;
}/*This is a function problem.You only need to complete the function given below*/
/*
The structure of linked list is the following
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// Function to remove duplicates from the linked list
// root: root of the linked list
Node *removeDuplicates(Node *root)
{
 // your code goes here
    if(root == NULL || root->next == NULL)
        return root;
        
    unordered_set<int> s;
    s.insert(root->data);
    
    Node* temp;
    temp = root;
    
    while(temp->next != NULL){
        if(s.find(temp->next->data) != s.end()){
            Node* temp1;
            temp1 = temp->next;
            temp->next = temp1->next;
            delete temp1;
        }
        
        else{
            s.insert(temp->next->data);
            temp = temp->next;
        }
    }
    
    return root;
}