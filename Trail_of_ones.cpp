/*
Given a number N, find the number of binary strings of length N that contains consecutive 1's in them.
 

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positve integer N, denoting the length of the binary string.


Output
Print out the count of strings having consecutive 1's in them.
 

Constraints
1 <= T <= 200
2 <= N <=30
*/

#include<vector>
#include<math.h>
using namespace std;

int trailOfOnes(int n){
    if(n == 0 || n == 1)
        return 0;
        
    if(n == 2)
        return 1;
        
    vector<int> dp(n + 1);
    dp[2] = 1;
    dp[3] = 3;
    
    for(int i=4; i<=n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + pow(2, i - 2);
        
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
	    
	    cout<<trailOfOnes(n)<<endl;
	}
	return 0;
}