/*
Given a singly linked list, delete middle  of the linked list. For example, if given linked list is 1->2->3->4->5 then linked list should be modified to 1->2->4->5.
If there are even nodes, then there would be two middle nodes, we need to delete the second middle element. For example, if given linked list is 1->2->3->4->5->6 then it should be modified to 1->2->3->5->6.

If the input linked list is NULL, then it should remain NULL. If the input linked list has 1 node, then this node should be deleted and new head should be returned.

Input:
First line of input contains number of testcases T. For each testcase, there will be two line of input, first of which contains number of nodes in the linked list and next line contains elements in the nodes of linked list.

Output:
Your function should return head  of the modified linked list.  If linked list is empty then it should return NULL.

User Task:
The task is to complete the function deleteMid() which should delete the middle element from linked list. 

Constraints:
1 <=T<= 50
1 <=N<= 1000
1 <=value<= 1000

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
1 2 4 5
2 4 6 5 1

Explanation:
Testcase 1: After deleting middle of the linked list, 3 will be deleted and the list will be as 1, 2, 4, 5.
*/

#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, struct Node **tail_ref,
           int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
struct Node* deleteMid(struct Node *head);

void printList(Node *head)
{
   while (head != NULL)
   {
      cout << head->data << " ";
      head = head->next;
   }
   cout << "\n";
}

/* Driver program to test above function*/
int main()
{
  int T,i,n,l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

    head = deleteMid(head);
    printList(head);
    }
    return 0;
}


/*This is a function problem.You only need to complete the function given below*/
/* Link list Node 
struct Node
{
    int data;
    struct Node* next;
}; */
// Deletes middle of linked list and returns head of the modified list
Node* deleteMid(Node *head)
{
     // Your Code Here
     
    if(head == NULL || head->next == NULL)
        return head;
        
    Node *slow, *fast, *prev;
    slow = head;
    fast = head;
    prev = NULL;
    
    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* temp;
    
    if(prev == NULL){
        temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    
    else{
        temp = slow;
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
    
    return head;
}