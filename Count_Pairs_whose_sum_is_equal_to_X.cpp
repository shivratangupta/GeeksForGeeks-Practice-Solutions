/*
Given two linked list of size N1 and N2 respectively of distinct elements, your task is to complete the function countPairs(), which returns the count of all pairs from both lists whose sum is equal to the given value X.

Input:
The function takes three arguments as input, reference pointer to the head of the two linked list (head1 and head2), and an variable X.
There will be T test cases and for each test case the function will be called separately.

Output:
For each test case the function should return the count of all the pairs from both lists whose sum is equal to the given value X. 

Constraints:
1<=T<=100
1<=N1,N2<=1000
1<=X<=10000
*/

/*
Structure of the node of the linked list is as
struct Node
{
   int data;
   struct Node* next;
};
*/
// your task is to complete this function 
int countPairs(struct Node* head1, struct Node* head2,	int x)
{
      //Code here
    if(head1 == NULL || head2 == NULL)
        return 0;
        
    int count;
    Node *temp, *temp1;
    
    count = 0;
    temp = head1;
    while(temp != NULL){
        temp1 = head2;
        while(temp1 != NULL){
            if(temp->data + temp1->data == x)
                count++;
            
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    
    return count;
}