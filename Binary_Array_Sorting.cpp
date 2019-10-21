/*
Given a binary array A[] of size N. The task is to arrange array in increasing order.

Note: The binary array contains only 0  and 1.

Input:
The first line of input contains an integer T, denoting the testcases. Every test case contains two lines, first line is N(size of array) and second line is space separated elements of array.

Output:
Space separated elements of sorted arrays. There should be a new line between output of every test case.

Constraints:
1 < = T <= 100
1 <= N <= 106
0 <= A[i] <= 1

Example:
Input:
2
5
1 0 1 1 0
10
1 0 1 1 1 1 1 0 0 0

Output:
0 0 1 1 1
0 0 0 0 1 1 1 1 1 1
*/


void sortBinary(vector<int> &nums){
    if(nums.size() == 0)
        return;
        
    int l, r;
    l = 0;
    r = nums.size() - 1;
    
    while(l < r){
        if(nums[l] == 0)
            l++;
            
        else{
            int temp;
            temp = nums[l];
            nums[l] = nums[r];
            nums[r] = temp;
            r--;
        }
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
	    
	    sortBinary(nums);
	    
	    for(int i=0; i<n; i++)
	        cout<<nums[i]<<" ";
	        
	    cout<<endl;
	}
	return 0;
}