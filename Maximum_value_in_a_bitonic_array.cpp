/*
Given an array of elements which is first increasing and then may be decreasing, find the maximum element in the array.
Note: If the array is increasing then just print then last element will be the maximum value.

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array, the second line of each test case contains N integers which are the array elements.

Output:
Print the maximum element in the array.

Constraints:
1 ≤ T ≤ 50
3 ≤ N ≤ 106
1 ≤ Ai ≤ 106

Example:
Input:
2
9
1 15 25 45 42 21 17 12 11
5
1 45 47 50 5

Output:
45
50

Explanation:
Testcase 1: Maximum element is 45 which is present at bitonic point.
*/


int maximumElement(vector<int> &nums){
    if(nums.size() == 0)
        return 0;
        
    int result;
    result = nums[0];
    
    for(int i=1; i<nums.size(); i++){
        if(nums[i] > result)
            result = nums[i];
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
	    
	    cout<<maximumElement(nums)<<endl;
	}
	return 0;
}