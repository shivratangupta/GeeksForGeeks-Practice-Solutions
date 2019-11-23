/*

Problems
Given a singly linked list of N nodes. The task is to find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked list is 1->2->3->4->5->6 then output should be 4.

Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains data of nodes of linked list.

Output:
For each testcase, there will be a single line of output containing data of middle element of linked list.

User Task:
The task is to complete the function getMiddle() which takes head reference as the only argument and should return the data at the middle node of linked list.

Constraints:
1 <= T <= 100
1 <= N <= 100

Example:
Input:
2
5
1 2 3 4 5
6
2 4 6 7 5 1

Output:
3
7

Explanation:
Testcase 1: Since, there are 5 elements, therefore 3 is the middle element at index 2 (0-based indexing).
*/



    int data;
    Node* next;
}; */
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   // Your code here
    if(head == NULL)
        return 0;
        
    Node *slow, *fast;
    slow = head;
    fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow->data;
}
