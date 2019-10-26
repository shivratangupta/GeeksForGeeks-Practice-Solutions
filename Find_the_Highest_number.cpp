/*
Given an array in such a way that the elements stored in array are in increasing order initially and then after reaching to a peak element , elements stored are in decreasing order. Find the highest element.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case consists of an integer n. The next line consists of n spaced integers. 

Output:
Print the highest number in the array.

Constraints: 
1<=T<=100
1<=n<=200
1<=a[i]<=105

Example:
Input:
2
11
1 2 3 4 5 6 5 4 3 2 1
5
1 2 3 4 5 

Output:
6
5
*/


int findNum(vector<int> &nums){
    int l, r, mid, n;
    n = nums.size();
    l = 0;
    r = n - 1;
    mid = (l + r) / 2;
    
    while(l <= r){
        if((mid == 0 || nums[mid - 1] < nums[mid]) && (mid == n || nums[mid + 1] < nums[mid]))
            return nums[mid];
            
        if(nums[mid] < nums[mid + 1])
            l = mid + 1;
            
        else
            r = mid - 1;
            
        mid = (l + r) / 2;
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
	    
	    cout<<findNum(nums)<<endl;
	}
	return 0;
}