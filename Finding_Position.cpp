/*
Some people are standing in a queue. A selection process follows a rule where people standing on even positions are selected. Of the selected people a queue is formed and again out of these only people on even position are selected. This continues until we are left with one person. Find out the position of that person in the original queue.

Input:
The first line of input contains an integer T denoting the number of test cases.The first line of each test case is N,number of people standing in a queue.

Output:
Print the position(original queue) of that person who is left.

Constraints:
1 <= T <= 103
1 <= N <= 108

Example:
Input
2
5
9

Output
4
8
*/


int findPosition(int n){
    if(n <= 1)
        return n;
        
    int result = 1;
    
    while(result < n)
        result *= 2;
        
    return result / 2;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    cout<<findPosition(n)<<endl;
	}
	return 0;
}