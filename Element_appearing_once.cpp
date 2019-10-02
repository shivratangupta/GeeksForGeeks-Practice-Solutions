/*
Given an sorted array A[i] of N positive integers having all the numbers occuring exactly twice, except for one number which will occur only once. Find the number occuring only once.

Input
The first line of input contains an integer T denoting the number of test cases. Then T test cases
follow. The first line of each test case contains a positive integer N, denoting the size of the array.
The second line of each test case contains a N positive integers, denoting the elements of the
array.


Output
Print out the singly occuring number.


Constraints
1 <= T  <= 100
0 <   N  <= 100
0 <= A[i] <= 100
*/

#include<vector>
using namespace std;

int uniqueDigits(vector<int> &nums){
    int result;
    result = 0;
    
    for(int i=0; i<nums.size(); i++)
        result ^= nums[i];
        
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
	    
	    cout<<uniqueDigits(nums)<<endl;
	}
	return 0;
}