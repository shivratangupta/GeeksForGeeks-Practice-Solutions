/*
A frog jumps either 1, 2 or 3 steps to go to top. In how many ways can it reach the top.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains one line of input N denoting the total number of steps.

Output:
For each testcase, in a new line, print the number of ways to reach the top.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 50

Example:
Input:
2
1
5
Output:
1
13
*/

#include<vector>
using namespace std;

int countHops(int n){
    if(n == 0)
        return 0;
        
    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i=3; i<=n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        
    return dp[n];
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    cout<<countHops(n)<<endl;
	}
	return 0;
}