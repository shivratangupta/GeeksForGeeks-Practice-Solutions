/*
Given an integer N, how many structurally unique binary search trees are there that store values 1...N?

Input:
First line of input contains T denoting the number of testcases. T testcases follow. Each testcase contains a single line of input containing N.

Ouput:
For each testcase, in a new line, print the answer.

Constraints:
1<=T<=15
1<=N<=11

Example:
Input:
2
2
3
Output:
2
5

Explanation:

Testcase1:
for N = 2, there are 2 unique BSTs
     1               2  
      \            /
       2         1

Testcase2:
for N = 3, there are 5 possible BSTs
  1              3        3         2      1
    \           /        /           /    \      \
     3        2         1        1    3      2
    /       /                \                      \
   2      1               2                        3
*/


int uniqueBST(int n, int k){
    if(k == 0)
        return 1;
        
    if(k > n - k)
        k = n - k;
        
    int result;
    result = 1;
    
    for(int i=k+1; i<=n; i++){
        result *= i;
        result /= (i - k);
    }
    
    return result / (k + 1);
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    cout<<uniqueBST(2 * n, n)<<endl;
	}
	return 0;
}