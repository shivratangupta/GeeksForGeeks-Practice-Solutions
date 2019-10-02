/*
A number (n) is represented in Linked List such that each digit corresponds to a node in linked list. Add 1 to it.

Input:
You have to complete the method which takes one argument: the head of the linked list. You should not read any input from stdin/console.. There are multiple test cases. For each test case, this method will be called individually

Output:
Your function should return pointer to head of the modified list.

Constraints:
1 <=T<= 50
1 <=n<= 10000
*/

/* Node structure
struct Node
{
    int data;
    Node* next;
}; */
// Should rearrange given linked list such that all even
// positioned Nodes are before odd positioned.
// Returns new head of linked List.
Node *addOne(Node *head)
{
   // Your Code here
    Node *curr, *prev, *next;
    curr = head;
    prev = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
    
    int carry, sum;
    Node* temp;
    temp = head;
    prev = NULL;
    carry = 1;
    
    while(temp != NULL && carry > 0){
        sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;
        prev = temp;
        temp = temp->next;
    }
    
    if(carry > 0){
        Node* temp1 = new Node();
        temp1->data = carry;
        temp1->next = NULL;
        
        if(prev != NULL)
            prev->next = temp1;
            
        else
            head = temp1;
    }
    
    curr = head;
    prev = NULL;
    
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head = prev;
    
    return head;
}