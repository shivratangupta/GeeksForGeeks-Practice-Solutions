/*
Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the output i.e you have to iterate on the original array only.

Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. Each testcase contains two lines of input. The first line contains a single integer N denoting the size of array.
The second line contains N space-separated integers denoting the elements of the array.

Output:
For each testcase, print the array in Zig-Zag fashion.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= Ai <= 10000

Example:
Input:
2
7
4 3 7 8 6 2 1
4
1 4 3 2
Output:
3 7 4 8 2 6 1
1 4 2 3
*/


void swap(vector<int> &nums, int i, int j){
    int temp;
    temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void zigzag(vector<int> &nums){
    if(nums.size() == 0)
        return;
        
    int n;
    n = nums.size();
        
    for(int i=0; i<n; i+=2){
        if(i > 0 && nums[i] > nums[i - 1])
            swap(nums, i, i - 1);
            
        if(i < n - 1 && nums[i] > nums[i + 1])
            swap(nums, i, i + 1);
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
	    
	    zigzag(nums);
	    
	    for(int i=0; i<n; i++)
	        cout<<nums[i]<<" ";
	        
	   cout<<endl;
	}
	return 0;
}