/*
Given a sorted array A of size N and a number X, you need to find the number of occurrences of X in A.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input: The first line contains N and X(element whose occurrence needs to be counted). The second line contains the elements of the array separated by spaces.

Output:
For each testcase, print the count of the occurrences of X in the array, if count is zero then print -1.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 105
1 ≤ A[i] ≤ 103
1 <= X <= 103

Example:
Input:
2
7 2
1 1 2 2 2 2 3
7 4
1 1 2 2 2 2 3
Output:
4
-1

Explanation:
Testcase 1: 2 occurs 4 times in 1 1 2 2 2 2 3
Testcase 2: 4 is not present in 1 1 2 2 2 2 3
*/


int numberOccurrence(vector<int> &nums, int k){
    if(nums.size() == 0)
        return 0;
        
    int l, r, mid, n, left, right;
    n = nums.size();
    left = -1;
    right = -1;
    l = 0;
    r = n - 1;
    mid = (l + r) / 2;
    
    while(l <= r){
        if(nums[mid] == k && (mid == 0 || nums[mid - 1] < nums[mid])){
            left = mid;
            break;
        }
        
        else if(nums[mid] < k)
            l = mid + 1;
            
        else
            r = mid - 1;
            
        mid = (l + r) / 2;
    }
    
    l = 0;
    r = n - 1;
    mid = (l + r) / 2;
    
    while(l <= r){
        if(nums[mid] == k && (mid == n - 1 || nums[mid + 1] > nums[mid])){
            right = mid;
            break;
        }
        
        else if(nums[mid] <= k)
            l = mid + 1;
            
        else
            r = mid - 1;
            
        mid = (l + r) / 2;
    }
    
    if(left == -1)
        return -1;
        
    return right - left + 1;
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
	    
	    cout<<numberOccurrence(nums, k)<<endl;
	}
	return 0;
}