/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.


Constraints:
1<=T<=30
1<=N<=50
1<=A[I]<=50


Example:
Input:
2
4
1 6 5 11
4
36 7 46 40

Output : 
1
23

Explaination :
Subset1 = {1, 5, 6}, sum of Subset1 = 12
Subset2 = {11},       sum of Subset2 = 11
*/

using namespace std;

int minimumSumPartition(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
    
    int n, sum;
    n = nums.size();
    sum = 0;
    
    for(int i=0; i<n; i++)
        sum += nums[i];
        
    vector<vector<bool> > dp(n + 1, vector<bool> (sum + 1, false));
    
    for(int i=0; i<=n; i++)
        dp[i][0] = true;
        
    for(int j=1; j<=sum; j++)
        dp[0][j] = false;
        
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i - 1][j];
            
            if(nums[i - 1] <= j)
                dp[i][j] = dp[i][j] | dp[i - 1][j - nums[i - 1]];
        }
    }
    
    int diff;
    diff = INT_MAX;
    
    for(int i=sum/2; i>=0; i--){
        if(dp[n][i] == true){
            diff = sum - 2 * i;
            break;
        }
    }
    
    return diff;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n;
	    cin>>n;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cout<<minimumSumPartition(nums)<<endl;
	}
	return 0;
}