/*
Given a linked list of N nodes where nodes can contain values 0s, 1s and 2s only. The task is to segregate 0s, 1s and 2s linked list such that all zeros segregate to headside, 2s at the end of the linked list and 1s in the mid of 0s and 2s.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains N elements as the data in the linked list.

Output Format:
For each testcase, segregate the 0s, 1s and 2s and display the linked list.

Your Task:
The task is to complete the function segregate() which segregate the nodes in the linked list as asked in the problem statement. The printing is done automatically by the driver code.

Constraints:
1 <= T <= 100
1 <= N <= 103

User Task:
The task is to complete the function sortList() which takes head reference as the argument and returns void.

Example:
Input:
2
8
1 2 2 1 2 0 2 2
4
2 2 0 1

Output:
0 1 1 2 2 2 2 2
0 1 2 2

Explanation:
Testcase 1: All the 0s are segregated to left end of the linked list, 2s to the right end of the list and 1s in between.
*/

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

struct Node* segregate(struct Node *head);

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}/*This is a function problem.You only need to complete the function given below*/
/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     Node *next;
  }
*/
// This function is to segregate the elememtns in the linked list
// This will do the required arrangement by changing the links
Node* segregate(Node *head) {
    
    // Add code here
    if(head == NULL || head->next == NULL)
        return head;
    
    int n;    
    Node* temp;
    temp = head;
    n = 0;
    
    while(temp->next != NULL){
        n++;
        temp = temp->next;
    }
    n++;
    
    Node* zero = new Node(0);
    Node* one = new Node(1);
    Node* two = new Node(2);
    
    Node *itr0, *itr1, *itr2, *next;
    itr0 = zero;
    itr1 = one;
    itr2 = two;
    
    temp = head;
    
    while(temp != NULL){
        next = temp->next;
        
        if(temp->data == 0){
            itr0->next = temp;
            itr0 = itr0->next;
        }
        
        else if(temp->data == 1){
            itr1->next = temp;
            itr1 = itr1->next;
        }
        
        else{
            itr2->next = temp;
            itr2 = itr2->next;
        }
        
        temp = next;
    }
    
    itr0->next = one->next ? one->next : two->next;
    itr1->next = two->next;
    itr2->next = NULL;
    
    head = zero->next;
    
    delete zero;
    delete one;
    delete two;
    
    return head;
}
