/*
Given a Linked list, rearrange it such that converted list should be of the form a < b > c < d > e < f .. where a, b, c are consecutive data node of linked list and such that the order of linked list is sustained.
For example: In 11 15 20 5 10 we consider only 11 20 5 15 10 because it satisfies the above condition and the order of linked list. 5 20 11 15 10 is not considered as it does not follow the order of linked list.

Input:
You have to complete the method which takes 1 argument: the head of the  linked list. You should not read any input from stdin/console. There are multiple test cases. For each test case, this method will be called individually.

Output:
Your function should return a pointer to the zig zack linked list.

Constraints:
1 <= T <= 100
1 <= size of linked list(a) <= 1000

Example:
Input:
2
4
1 2 3 4 
5
11 15 20 5 10

Output:
1 3 2 4
11 20 5 15 10

Example:
Testcase 2: In the given linked list, after arranging them as 11 < 20 > 5 < 15 > 10 in the pattern as asked above.
*/

/*
struct Node
{
int data;
Node* next;
};
*/
Node *zigZack(Node* head)
{
 // your code goes here
    if(head == NULL)
        return head;
        
    bool flag;
    Node* temp;
    temp = head;
    flag = true;
    
    while(temp->next != NULL){
        if(flag){
            if(temp->data > temp->next->data){
                int temp1;
                temp1 = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp1;
            }
        }
        
        else{
            if(temp->data < temp->next->data){
                int temp1;
                temp1 = temp->data;
                temp->data = temp->next->data;
                temp->next->data = temp1;
            }
        }
        
        temp = temp->next;
        flag = !flag;
    }
    
    return head;
}