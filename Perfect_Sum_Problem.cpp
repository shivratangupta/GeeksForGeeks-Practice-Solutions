/*
Given an array of integers and a sum, the task is to count all subsets of given array with sum equal to given sum.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an nteger n denoting the size of the array. The next line contains n space separated integers forming the array. The last line contains the sum.

Output:
Count all the subsets of given array with sum equal to given sum.

Constraints:
1<=T<=10^5
1<=n<=10^5
1<=a[i]<=10^5
1<=sum<=10^5

Example:
Input:
2
6
2 3 5 6 8 10
10
5
1 2 3 4 5
10

Output:
3
3
*/


void subsetRec(vector<int> &nums, vector<vector<bool> > &dp, int i, int sum, int &result){
    if(i == 0 && sum != 0 && dp[0][sum]){
        result++;
        return;
    }
    
    if(i == 0 && sum == 0){
        result++;
        return;
    }
        
    if(dp[i - 1][sum])
        subsetRec(nums, dp, i - 1, sum, result);
        
    if(sum >= nums[i] && dp[i-1][sum-nums[i]])
        subsetRec(nums, dp, i - 1, sum - nums[i], result);
}

int perfectSum(vector<int> &nums, int k){
    if(nums.size() == 0)
        return 0;
        
    int n;
    n = nums.size();
    
    vector<vector<bool> > dp(n, vector<bool> (k + 1, false));
    for(int i=0; i<n; i++)
        dp[i][0] = true;
        
    if(nums[0] <= k)
        dp[0][nums[0]] = true;
    
    for(int i=1; i<n; i++){
        for(int j=0; j<k+1; j++){
            dp[i][j] = dp[i - 1][j];
            
            if(nums[i] <= j)
                dp[i][j] = dp[i][j] | dp[i - 1][j-nums[i]];
        }
    }
    
    if(!dp[n - 1][k])
        return 0;
        
    int result;
    result = 0;
    
    subsetRec(nums, dp, n-1, k, result);
    
    return result;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, k;
	    cin>>n;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    cin>>k;
	    
	    cout<<perfectSum(nums, k)<<endl;
	}
	return 0;
}