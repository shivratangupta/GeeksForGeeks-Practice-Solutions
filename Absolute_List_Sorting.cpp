/*
Given a linked list L of N nodes, sorted in ascending order based on the absolute values of its data. Sort the linked list according to the actual values.
Ex: Input : 1 -> -2 -> -3 -> 4 -> -5 
      Output: -5 -> -3 -> -2 -> 1 -> 4

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. The first line of each test case contains a positive integer N denoting the size of linked list. The second line of each test case contains N space separated integers denoting the values of N nodes.


Output
Corresponding to each test case, the expected output will be space separated values of the sorted linked list.


Constraints
1 <= T <= 100
0 <   N  <= 30
-100 <= L[i] <= 100
*/

/* The structure of the Linked list Node is as follows:
struct Node
{
    Node* next;
    int data;
}; */
/*Your method shouldn't print anything
 it should transform the passed linked list */
void sortList(Node** head)
{
    // Your Code Here
    
    if(*head == NULL)
        return;
        
    Node *temp, *prev;
    prev = *head;
    temp = (*head)->next;
    
    while(temp != NULL){
        if(temp->data < prev->data){
            prev->next = temp->next;
            temp->next = *head;
            *head = temp;
            temp = prev->next;
        }
        
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}