/*
Given Pointer/Reference to the head of the linked list, the task is to Sort the given linked list using Merge Sort.

Note: If the length of linked list is odd, then the extra node should go in the first list while splitting.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains number of nodes in the linked list and next line contains N elements of the linked list.

Output:
For each test, in a new line, print the sorted linked list.

Your Task:
For C++ and Python: The task is to complete the function mergeSort() which sort the linked list using merge sort function.
For Java: The task is to complete the function mergeSort() and return the node which can be used to print the sorted linked list.

Constraints:
1 <= T <= 100
1 <= N <= 105
*/

/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
/* Function to mergesort the linked list
   It should return head of the modified list  */
   
Node* merge(Node* head1, Node* head2){
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
        
    if(head1->data <= head2->data)
        head1->next = merge(head1->next, head2);
        
    else{
        Node* temp;
        temp = head2;
        head2 = head2->next;
        temp->next = head1;
        head1 = temp;
        head1->next = merge(head1->next, head2);
    }
    
    return head1;
}

Node* mergeSort(Node* head) {
    // your code here
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *slow, *fast;
    slow = head;
    fast = head->next;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    Node* head1;
    head1 = slow->next;
    slow->next = NULL;
    
    return merge(mergeSort(head), mergeSort(head1));
}
