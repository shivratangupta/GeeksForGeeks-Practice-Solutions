/*
Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.

Input:
The first line of input consists of T, the number of the test cases. T testcases follow. Each testcase contains two lines of input.
The first line of each test case contains the size of the array, and the second line has the elements of the array.

Output:
For each testcase, in a new line, print the number that appears only once in the array.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 1017

Example:
Input:
1
11
1 1 2 2 3 3 4 50 50 65 65
Output:
4
*/


void search(vector<int> &nums, int l, int r){
    if(l > r)
        return;
        
    if(l == r){
        cout<<nums[l];
        return;
    }
    
    int mid;
    mid = (l + r) / 2;
    
    if(mid % 2 == 0){
        if(nums[mid] == nums[mid + 1])
            search(nums, mid + 2, r);
            
        else
            search(nums, l, mid);
    }
    
    else{
        if(nums[mid] == nums[mid - 1])
            search(nums, mid + 1, r);
            
        else
            search(nums, l, mid - 1);
    }
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
	    
	    search(nums, 0, n - 1);
	    
	    cout<<endl;
	}
	return 0;
}