/*
Given an array of positive integers where all numbers occur even number of times except one number which occurs odd number of times. Find the number.

Input:
The first line of input contains a single integer T denoting the number of test cases. Then T test cases follow. Each test case consist of two lines. The first line of each test case consists of an integer N, where N is the size of array. The second line of each test case contains N space separated integers denoting array elements.

 

Output:
Corresponding to each test case, print the number which occur odd number of times. If no such element exists, print 0.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
1 ≤ A[i] ≤ 106

Example:
Input:
1
5
8 4 4 8 23
Output:
23

Explanation:
Testcase 1: 23 is the element which occurs odd number of times.
*/



int findOddOccurence(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
        
    int result;
    result = 0;
    
    for(int i=0; i<nums.size(); i++)
        result ^= nums[i];
        
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
	    
	    cout<<findOddOccurence(nums)<<endl;
	}
	return 0;
}