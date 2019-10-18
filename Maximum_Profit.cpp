/*
In stock market , a person buys a stock and sells it on some future date. Given the stock prices of N days in an form of an array A[ ] and a positive integer K, find out the maximum profit a person can make in atmost K transactions. A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. 
The first line of each test case contains a positve integer K, denoting the number of transactions.
The second line of each test case contains a positve integer N, denoting the length of the array A[ ].
The third line of each test case contains a N space separated positive integers, denoting the prices of each day in the array A[ ].


Output
Print out the maximum profit earned by the person.
No profit will be equivalent to 0.


Constraints
1 <= T <= 100
0 <   K <= 10
2 <= N <=30
0 <= A[ ] <= 1000

Examples 

Input
3
2
6
10 22 5 75 65 80
3
4
20 580 420 900
1
5
100 90 80 50 25

Output
87
1040
0
 

Explanation:
Output 1: Trader earns 87 as sum of 12 and 75  i.e. Buy at price 10, sell at 22, buy at  5 and sell at 80
Output 2: Trader earns 1040 as sum of 560 and 480 i.e. Buy at price 20, sell at 580, buy at 420 and sell at 900
Output 3: Trader cannot make any profit as selling price is decreasing day by day.Hence, it is not possible to earn anything.
*/

using namespace std;

int maximumProfit(vector<int> &prices, int k){
    if(prices.size() == 0)
        return 0;
        
    int n;
    n = prices.size();
    
    vector<vector<int> > dp(k + 1, vector<int> (n));
    
    for(int i=0; i<=k; i++){
        int prevdiff;
        prevdiff = INT_MIN;
        for(int j=0; j<n; j++){
            if(i == 0)
                dp[i][j] = 0;
                
            else if(j == 0)
                dp[i][j] = 0;
                
            else{
                prevdiff = max(prevdiff, dp[i - 1][j - 1] - prices[j - 1]);
                dp[i][j] = max(dp[i][j - 1], prevdiff + prices[j]);
            }
        }
    }
    
    return dp[k][n - 1];
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, k;
	    cin>>k>>n;
	    
	    vector<int> prices;
	    for(int i=0; i<n; i++){
	        int price;
	        cin>>price;
	        prices.push_back(price);
	    }
	    
	    cout<<maximumProfit(prices, k)<<endl;
	}
	return 0;
}