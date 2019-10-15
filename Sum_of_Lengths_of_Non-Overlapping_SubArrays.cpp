/*
Given an array of N elements, you are required to find the maximum sum of lengths of all non-overlapping subarrays with K as the maximum element in the subarray.
.
Input:
First line of the input contains an integer T, denoting the number of the total test cases. Then T test case follows. First line of the test case contains an integer N, denoting the number of elements in the array. Then next line contains N space separated integers denoting the elements of the array. The last line of each test case contains an integer K.

Output:
For each test case ouptut a single line denoting the sum of the length of all such subarrays.

Constraints:
1 <= T <= 100
1 <= N <= 105
1 <= A[] <= 105

Example:
Input:
3
9 
2 1 4 9 2 3 8 3 4
4
7
1 2 3 2 3 4 1
4
10
4 5 7 1 2 9 8 4 3 1
4
Output:
5
7
4
Explanation:
Test Case 1:
{2, 1, 4} => Length = 3
{3, 4} => Length = 2
So, 3 + 2 = 5 is the answer

Test Case 2: {1, 2, 3, 2, 3, 4, 1} => Length = 7

Test Case 3:
{4} => Length = 1
{4, 3, 1} => Length = 3
So, 1 + 3 = 4 is the answer.
*/


int sumLengthSub(vector<int> &nums, int k){
    if(nums.size() == 0)
        return 0;
        
    int n, count, result;
    bool flag;
    n = nums.size();
    result = 0;
    
    for(int i=0; i<n;){
        count = 0;
        flag = false;
        
        while(i < n && nums[i] <= k){
            count++;
            
            if(nums[i] == k)
                flag = true;
                
            i++;
        }
        
        if(flag)
            result += count;
            
        while(i < n && nums[i] > k)
            i++;
    }
    
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
	    
	    cout<<sumLengthSub(nums, k)<<endl;
	}
	return 0;
}