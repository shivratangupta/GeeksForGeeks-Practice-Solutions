/*
Given an array of integers (A[])  and a number x, find the smallest subarray with sum greater than the given value.

Examples:
A[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}

A[] = {1, 10, 5, 2, 7}
   x  = 9
Output: 1
Minimum length subarray is {10}

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains two space separated integers N and x. Then in the next line are N space separated values of the array.

Output:
For each test case in a new line print the required ouput.

Constraints:
1<=T<=100
1<=N,x<=1000
1<=A[]<=1000

Example:
Input:
2
6 51
1 4 45 6 0 19
5 9
1 10 5 2 7
Output:
3
1
*/


int smallestSubSum(vector<int> &nums, int k){
    if(nums.size() == 0)
        return 0;
        
    int n, start, end, sum, length, currlen;
    n = nums.size();
    start = 0;
    end = 0;
    sum = 0;
    length = n;
    
    while(end < n){
        sum += nums[end];
        
        while(sum > k){
            currlen = end - start + 1;
            if(currlen < length)
                length = currlen;
            
            sum -= nums[start];
            start++;
        }
        
        end++;
    }
    
    return length;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int l=0; l<t; l++){
	    int n, k;
	    cin>>n>>k;
	    
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cout<<smallestSubSum(nums, k)<<endl;
	}
	return 0;
}