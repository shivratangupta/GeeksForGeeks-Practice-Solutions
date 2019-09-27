/*
Given an unsorted array arr[] of size N, rotate it by D elements (clockwise). 

Input:
The first line of the input contains T denoting the number of testcases. First line of eacg test case contains two space separated elements, N denoting the size of the array and an integer D denoting the number size of the rotation. Subsequent line will be the N space separated array elements.

Output:
For each testcase, in a new line, output the rotated array.

Constraints:
1 <= T <= 200
1 <= N <= 107
1 <= D <= N
0 <= arr[i] <= 105
*/

#include<vector>
#include<algorithm>
using namespace std;

void rotateArray(vector<int> &nums, int k){
    if(k == 0)
        return;
    
    int n;
    n = nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + n - k);
    reverse(nums.begin() + n - k, nums.end());
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	for(int k=0; k<t; k++){
	    int n, r;
	    cin>>n>>r;
	    vector<int> nums;
	    for(int i=0; i<n; i++){
	        int num;
	        cin>>num;
	        nums.push_back(num);
	    }
	    
	    rotateArray(nums, r);
	    
	    for(int i=0; i<n; i++)
	        cout<<nums[i]<<" ";
	        
	   cout<<endl;
	}
	return 0;
}