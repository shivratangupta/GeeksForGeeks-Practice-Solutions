/*
There are two singly linked lists of size N and M in a system. But, due to some programming error the end node of one of the linked list got linked into one of the node of second list, forming a inverted Y shaped list. Write a program to get the point where two linked lists intersect each other.

Y ShapedLinked List
Above diagram shows an example with two linked list having 15 as intersection point.
Note: Expected time complexity is O(m + n) where m and n are lengths of two linked lists.

Input:
First line of input is the number of test cases T. Every test case has four lines. First line of every test case contains three numbers, x (number of nodes before merge point in 1st list), y (number of nodes before merge point in 11nd list) and z (number of nodes after merge point). Next three lines contain x, y and z values.

Output:
Print the data of the node in the linked list where two linked lists intersects.

Your Task:
The task is to complete the function intersetPoint() which finds the point of intersection of two linked list. The function should return data value of a node where two linked lists merge. If linked list do not merge at any point, then it shoudl return -1.

Constraints:
1 <= T <= 50
1 <= N <= 100
1 <= value <= 1000

Example:
Input:
2
2 3 2
10 20
30 40 50
5 10
2 3 2
10 20
30 40 50
10 20

Output:
5
10

Explanation:
Testcase 1: The point of intersection of two linked list is 5, means both of them get linked (intersects) with each other at node whose value is 5.
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

int intersectPoint(struct Node* head1, struct Node* head2);

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        tail1->next = head3;
        if (tail2 != NULL)
        tail2->next = head3;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    if(head1 == NULL || head2 == NULL)
        return -1;
        
    int m, n;
    Node* temp;
    
    temp = head1;
    m = 0;
    
    while(temp != NULL){
        m++;
        temp = temp->next;
    }
    
    temp = head2;
    n = 0;
    
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    
    Node *temp1, *temp2;
    temp1 = head1;
    temp2 = head2;
    
    if(m > n){
        for(int i=0; i<m-n; i++)
            temp1 = temp1->next;
    }
    
    else{
        for(int i=0; i<n-m; i++)
            temp2 = temp2->next;
    }
    
    while(temp1 != NULL && temp2 != NULL && temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    if(temp1 == NULL && temp2 == NULL)
        return -1;
        
    return temp1->data;
}
