/*
Given two linked lists, your task is to complete the function makeUnion(), that returns the union of two linked lists. This union should include all the distinct elements only.

Input:
The function takes 2 arguments, reference pointer to the head of the first linked list (head1) and reference pointer to the head of the second linked list (head2). 
There are multiple test cases and for each test case this function will be called separately.

Output:
The function should return reference pointer to the head of the new list that is formed by the union of the two the lists. 
Note: The new list formed should be in non-decreasing order.

User Task:
The task is to complete the function makeUnion() which makes the union of the given two lists.

Constraints:
1<=T<=100
1<=N<=103
*/

/*
structure of the node is as
struct node
{
	int data;
	struct node* next;
};
*/
struct node* makeUnion(struct node* head1, struct node* head2)
{
    // code here
    set<int> s;
    node* temp;
    temp = head1;
    
    while(temp != NULL){
        s.insert(temp->data);
        temp = temp->next;
    }
    
    temp = head2;
    
    while(temp != NULL){
        s.insert(temp->data);
        temp = temp->next;
    }
    
    node* head;
    head = NULL;
    
    set<int> :: iterator it;
    
    for(it = s.begin(); it != s.end(); it++){
        node* temp1 = new node();
        temp1->data = *it;
        temp1->next = NULL;
        
        if(head == NULL){
            head = temp1;
            temp = head;
        }
        
        else{
            temp->next = temp1;
            temp = temp->next;
        }
    }
    
    return head;
}
