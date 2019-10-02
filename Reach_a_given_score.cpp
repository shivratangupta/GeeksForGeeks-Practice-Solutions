/*
Consider a game where a player can score 3 or 5 or 10 points in a move. Given a total score n, find number of distinct combinations to reach the given score.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow.The first line of each test case is n.

Output:
For each testcase, in a new line, print number of ways/combinations to reach the given score.

Constraints:
1 ≤ T ≤ 100
1 ≤ n ≤ 1000
*/

#include<vector>
using namespace std;

int waysToReach(int n){
    if(n < 3)
        return 0;
        
    vector<int> dp(n + 1);
    dp[0] = 1;
    
    for(int i=3; i<=n; i++)
        dp[i] += dp[i - 3];
        
    for(int i=5; i<=n; i++)
        dp[i] += dp[i - 5];
        
    for(int i=10; i<=n; i++)
        dp[i] += dp[i - 10];
    
    return dp[n];
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n;
	    cin>>n;
	    cout<<waysToReach(n)<<endl;
	}
	return 0;
}