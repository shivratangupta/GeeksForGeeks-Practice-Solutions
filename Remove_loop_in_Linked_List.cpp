/*
You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.

Input:
First line of input contains number of testcases T. T testcases follow. For each testcase, first line of input contains length N of the linked list and next line contains N data of the linked list. The third line contains the position of the node(from head) to which the last node will get connected. If it is 0 then there is no loop.

Output:
For each testcase, in a new line, 1 will be printed if loop is removed(correct answer) else 0 will be printed(for wrong answer).

User Task:
You don't have to read the input, or print the output. Just complete the function removeTheLoop() which has only argument as head reference of the linked list. If you complete this function in correct way and loop gets removed, the answer will be 1.

Constraints:
1 <= T <= 50
1 <= N <= 300

Example:
Input:
2
3
1 3 4
2
4
1 8 3 4
0

Output:
1
1

Explanation:
Testcase 1: In the first test case N = 3.
The linked list with nodes N = 3 is given. Here, x = 2 which means last node is connected with xth node of linked list. Therefore, there exists a loop. 

Testcase 2: N = 4 and x = 0, which means lastNode->next = NULL, thus the Linked list does not contains any loop.
*/

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *head)
{
     //Your code here
    if(head == NULL || head->next == NULL)
        return;
        
    Node *slow, *fast;
    slow = head;
    fast = head;
    
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast)
            break;
    }
    
    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        
        fast->next = NULL;
    }
}
