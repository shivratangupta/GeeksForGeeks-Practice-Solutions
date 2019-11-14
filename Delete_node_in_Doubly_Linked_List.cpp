/*
Given a doubly linked list and a position. The task is to delete a node from given position in a doubly linked list.

Input:
First line of input contains number of testcases. First line of each testcase contains number of elements in the linked list and next line contains the elements of the linked list. The last line contains the position from which element is to be deleted.

Output:
Delete the node from the given doubly linked list and set *head_ref if required.

User Task:
The task is to complete the function deleteNode() which should delete the node at given position.

Constraints:
1 <= T <= 300
2 <= N <= 100
1 <= x <= N

Example:
Input:
2
3
1  3 4
3
4
1 5 2 9                    
1

Output:
1 3           
5 2 9

Explanation:
Testcase 1: After deleting the node at position 3 (position starts from 1), the linked list will be now as 1->3.
*/


/*
struct Node{
  int data;
  Node *next;
  Node *prev;
};
 */
void deleteNode(Node **head_ref, int x)
{
  //Your code here
    if(*head_ref == NULL)
        return;
        
    if(x == 1){
        Node* temp;
        temp = *head_ref;
        *head_ref = temp->next;
        if(temp->next != NULL)
            temp->next->prev = NULL;
            
        temp->next = NULL;
        delete temp;
        return;
    }
    
    Node* temp;
    temp = *head_ref;
    
    for(int i=0; i<x-1; i++)
        temp = temp->next;
        
    temp->prev->next = temp->next;
    
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev = NULL;
    temp->next = NULL;
    delete temp;
}