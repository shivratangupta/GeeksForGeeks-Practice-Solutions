/*
Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…
For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

Note: It is recommended do this in-place without altering the nodes' values.

Input:
First line of input contains number of testcases T. For each testcase, there will be two lines of input, first of which contains length of linked list and next line contains elements of the nodes of linked list.

Output:
Reorder it as explained above.

User Task:
The task is to complete the function reorderList() which should reorder the list as required.

Constraints:
1 <= T <= 200
1 <= N <= 200

Example:
Input:

2
3
1 2 3
4
1 7 3 4

Output:
1 3 2
1 4 7 3

Explanation:
Testcase 2: After rearranging the given list as required, we have list as 1 -> 4 -> 7 -> 3.
*/

using namespace std;
/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
};
 void reorderList(struct Node* head) ;
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = (struct Node *) malloc(sizeof(struct Node));
    new_Node->data = data;
    new_Node->next = NULL;
    return new_Node;
}
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node *head)
{
	struct Node* temp;
    while(head != NULL)
    {
        
        temp=head;
        head = head->next;
        free(temp);
    }
  
}
int main(void)
{
   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {
	   struct Node* temp,*head;
	    cin>>n;
	    cin>>x;
	    head=newNode(x);
	    temp=head;
	    for(i=0;i<n-1;i++)
	    {
			cin>>x;
			temp->next=newNode(x);
			temp=temp->next;
			}
	   
		reorderList(head);
	    printList(head);
freeList(head);
   }
   return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/* Following is the Linked list node structure */
/*struct Node
{
    int data;
    Node* next;
};*/
void reorderList(Node* head) 
{
    // Your code here
    if(head == NULL || head->next == NULL)
        return;
        
    int n;
    Node* temp;
    temp = head;
    
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    
    temp = head;
    
    for(int i=0; i<n/2; i++)
        temp = temp->next;
        
    Node* temp1;
    temp1 = temp->next;
    temp->next = NULL;
    
    Node *curr, *prev, *next;
    curr = temp1;
    prev = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    temp1 = prev;
    
    temp = head;
    
    while(temp1 != NULL){
        Node* temp2;
        temp2 = temp1;
        temp1 = temp1->next;
        temp2->next = temp->next;
        temp->next = temp2;
        temp = temp->next->next;
    }
}