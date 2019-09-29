/*
Given an unsorted array, find the minimum difference between any pair in given array.

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is N, the size of array. Second line of the test case is the Array.

Output:

Print the minimum difference between any two pairs.

Constraints:

1 <= T <= 30
1 < N <= 100
1 <= arr[i] <= 100000
*/

#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

int minDiff(vector<int> &nums){
    if(nums.size() < 2)
        return 0;
        
    sort(nums.begin(), nums.end());
    
    int mind;
    mind = INT_MAX;
    for(int i=1; i<nums.size(); i++){
        if(nums[i] - nums[i - 1] < mind)
            mind = nums[i] - nums[i - 1];
    }
    
    return mind;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n;
	    cin>>n;
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    cout<<minDiff(nums)<<endl;
	}
	return 0;
}