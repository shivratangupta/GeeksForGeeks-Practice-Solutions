/*
Given a priority queue (max heap) and Q queries to be performed on priority queue. The task is to perform operations based on queries.
1. p : query to push element (x, given with query) to priority_queue and print size.
2. pp : query to pop element from priority_queue and print size.
3. t : query to return top element of priority_queue, if empty -1 will be printed.

Input Format:
First line of input contains number of testcases T. For each testcase, first line of input contains Q queries. Next Q lines contains Q queries.

Output Format:
For each testcase, perform the required operation, and print if anything required.

Your Task:
Your task is to complete the functions push_pq(), pp_pq() and pq_top(), so that the queries are performed.

Constraints:
1 <= T <= 100
1 <= Q <= 100
*/

//User function Template for C++
/* Function to implement top operation in priority_queue
* pq : priority_queue
* x : element to be pushed
*/
void push_pq(priority_queue<int, vector<int>, greater<int>> &pq, int x){
    
    // Your code here
    
    pq.push(x);
    
}
/* Function to implement top operation in priority_queue
* pq : priority_queue
*/
void pp_pq(priority_queue<int, vector<int>, greater<int>> &pq){
   
    if(!pq.empty())
    /*Your code here*/
    pq.pop();
    return;
    
}
/* Function to implement pop operation in priority_queue
* pq : priority_queue
*/
int pq_top(priority_queue<int, vector<int>, greater<int>> &pq){
    
    if(!pq.empty())
    /*Your code here*/
    return pq.top();
    else
    return -1;
    
}