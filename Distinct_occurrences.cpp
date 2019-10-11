/*
Given two strings S and T, find count of distinct occurrences of T in S as a sub-sequence. Your task is to complete the function subsequenceCount which takes two strings as argument S and T and returns the count of the sub-sequences.

Input:
The first line of input contains an integer t denoting the no of test cases . Then t test cases follow. The first line of each test case contains 2 strings S and T.

Output:
For each test case in a new line print the count of distinct occurrences of T in S as a sub-sequence.

Constraints:
1<=t<=100
1<=length of (S,T)<=100
*/

/*You are required to complete this method*/
int subsequenceCount(string S, string T)
{
  //Your code here
    int m, n;
    m = T.size();
    n = S.size();
    
    vector<vector<int> > dp(m + 1, vector<int> (n + 1));
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0)
                dp[i][j] = 1;
                
            else if(j == 0)
                dp[i][j] = 0;
                
            else if(T[i - 1] != S[j - 1])
                dp[i][j] = dp[i][j - 1];
                
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
        }
    }
    
    return dp[m][n];
}
 
