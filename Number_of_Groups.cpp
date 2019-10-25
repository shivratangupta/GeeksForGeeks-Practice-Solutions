/*
Given an array Arr[] of N distinct integers. Write a program to find the count of groups of 2 or 3 integers that can be formed by choosing integers from the given array such that sum of integers in each of the group is divisible by three.

Input:
First line of input contains a single integer T which denotes the number of test case. Then T test case follows. First line of each test case contains a single integer N which denotes number of elements in the array. Second line of each test case contains N space separated integers.

Output:
For each test case, print the count of all the groups of 2 or 3 integers formed from the given array such that sum of elements in the group is divisible by 3.

Constraints:
1<=T<=100
1<=N<=105
1<=Arr[i]<=105

Example:
Input:
2
6
1 5 7 2 9 14
4
3 6 9 12
Output:
13
10
*/


int groupCounts(vector<int> &nums){
    if(nums.size() < 2)
        return 0;
        
    int r1, r2, r3;
    r1 = 0;
    r2 = 0;
    r3 = 0;
    
    for(int i=0; i<nums.size(); i++){
        if(nums[i] % 3 == 0)
            r1++;
           
        else if(nums[i] % 3 == 1)
            r2++;
            
        else
            r3++;
    }
    
    int result;
    result = 0;
    
    result += r2 * r3 + (r1 * (r1 - 1) / 2);
    result += r1 * (r1 - 1) * (r1 - 2) / 6;
    result += r2 * (r2 - 1) * (r2 - 2) / 6;
    result += r3 * (r3 - 1) * (r3 - 2) / 6;
    result += r1 * r2 * r3;
    
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
	    
	    cout<<groupCounts(nums)<<endl;
	}
	return 0;
}