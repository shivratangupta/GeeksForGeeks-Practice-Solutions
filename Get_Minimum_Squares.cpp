/*
Given a number N. You need to write a program to print the minimum number of squares of this number that sums to N. For Example: If N = 100 , N can be expressed as (10*10) and also as (5*5 + 5*5 + 5*5 + 5*5) but the output will be 1 as minimum number of square is 1 , i.e (10*10).

Input:
First line of input contains a single integer T, which denotes the number of test cases. Then T test cases follows. First line of each test case contains a single integer N.
Output:
For each test case print the minimum number of squares that sums to N.

Constraints:
1<=T<=100
1<=N<=104

Example:
Input:
3
100
6
25
Output:
1
3
1
*/

using namespace std;

int getMinimumSquares(int n){
    if(n <= 3)
        return n;
        
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i=4; i<n+1; i++){
        dp[i] = i;
        
        for(int j=1; j<=ceil(sqrt(i)); j++){
            int temp;
            temp = j * j;
            
            if(temp > i)
                break;
            
            else    
                dp[i] = min(dp[i], 1 + dp[i - temp]);
        }
    }
    
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
	    
	    cout<<getMinimumSquares(n)<<endl;
	}
	return 0;
}