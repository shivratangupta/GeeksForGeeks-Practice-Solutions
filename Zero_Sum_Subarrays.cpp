/*
You are given an array A of size N. You need to print the total count of sub-arrays having their sum equal to 0

Input:
First line of the input contains an integer T denoting the number of test cases. Each test case consists of two lines. First line of each test case contains an Integer N denoting the size of the array, and the second line contains N space separated integers.

Output:
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Constraints:    
1 <= T <= 100
1<= N <= 107
-1010 <= Ai <= 1010

Example:
Input:
2
6
0 0 5 5 0 0
10
6  -1 -3 4 -2 2 4 6 -12 -7

Output:
6
4
*/


int zeroSumSubarray(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
        
    int n, result, sum;
    unordered_map<int, vector<int> > m;
    n = nums.size();
    result = 0;
    sum = 0;
    
    for(int i=0; i<n; i++){
        sum += nums[i];
        
        if(sum == 0)
            result++;
            
            
        if(m.find(sum) != m.end())
            result += m[sum].size();
            
        m[sum].push_back(i);
    }
    
    return result;
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
	    
	    cout<<zeroSumSubarray(nums)<<endl;
	}
	return 0;
}